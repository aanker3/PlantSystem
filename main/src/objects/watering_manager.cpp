#include "watering_manager.h"
#include "Arduino.h"

// Constructor - Initialize Variables
WateringManager::WateringManager(){
}

WateringManager::~WateringManager(){
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    delete it->plant;
    it->plant = NULL;
  }
}

void WateringManager::printPlantSystemsInfo() const {
  int plantNum = 0;
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    Serial.println("Plant " + String(plantNum));
    Serial.println((it->plant->getName()).c_str());
    Serial.println("MoistureWateringPoint = " + String(it->plant->getMoistureWateringPoint()));
    Serial.println("Moisture pin: " + String(it->moistureSensor.getHwPin()) + "measured_value = " + String(it->moistureSensor.getMeasuredValue()));

    Serial.println(it->motor.getHwPin());
    plantNum++;
  }
}

void WateringManager::gatherSensorData()
{
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    it->plant->setCurrentMoistureValue(it->moistureSensor.getMeasuredValue());
  }
}

void WateringManager::waterPlantsIfNeeded()
{
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    if(it->plant->getMoistureWateringPoint() > it->plant->getCurrentMoistureValue())
    {
      if (it->plant->getTimesWatered() < it->plant->getMaxWaterTwoWeeks())
      {
        Serial.println("WATERING " + String((it->plant->getName()).c_str()) + " PLANT!");
        it->plant->plantWatered();
        Serial.println(String((it->plant->getName()).c_str()) + " Has been watered " + String(it->plant->getTimesWatered()) + " times");
        
        unsigned long wateringTime = getWaterTime(it->plant->getPotSize());
        Serial.println("Watering for " + String(wateringTime/1000) + " Seconds");
        it->motor.turnOn();

        //Delay = blocking function w/ weight sensor
        delay(wateringTime);
        it->motor.turnOff();
      }
      else
      {
        Serial.println("Plant " + String((it->plant->getName()).c_str()) + " Watered TOO MANY TIMES!");
      }
    }
  }
}

void WateringManager::PrintTwoWeekResults()
{
  //todo Log output to sd card.
  Serial.println("------------- 2 Week Results -------------");
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    Serial.println(String((it->plant->getName()).c_str()) + " Has been watered " + String(it->plant->getTimesWatered()) + " times.  MAX Water per 2 week = " + String(it->plant->getMaxWaterTwoWeeks()));
  }
  Serial.println("------------- -------------- -------------");
}

void WateringManager::resetPlants()
{
  PrintTwoWeekResults();
  Serial.println("RESETTING PLANTS");
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    it->plant->reset();
  }
}

void WateringManager::addPlantSystem(const std::string& plantName, PotSize potSize, uint8_t moistureSensorPin, uint8_t motorPin)
{
  Plant* plant = PlantFactory::createPlant(plantName, potSize);
  if (plant==NULL)
  {
    Serial.println("Error Plant is NULL.  Plant name not found");
    return;
  }
  MoistureSensor moistureSensor = MoistureSensor(moistureSensorPin);
  Motor motor = Motor(motorPin);
  PlantSystem newPlantSystem = {plant, moistureSensor, motor};
  plantSystems.push_back(newPlantSystem);
}