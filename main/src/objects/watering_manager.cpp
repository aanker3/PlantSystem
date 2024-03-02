#include "watering_manager.h"
#include "Arduino.h"

// Constructor - Initialize Variables
WateringManager::WateringManager(){
}

WateringManager::~WateringManager(){
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    delete it->plant;
  }
}

void WateringManager::printPlantSystemsInfo() const {
  int plantNum = 0;
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    Serial.println("Plant " + String(plantNum));
    Serial.println((it->plant->getName()).c_str());
    Serial.println("MoistureWateringPoint = " + String(it->plant->getMoistureWateringPoint()));
    Serial.println("pin: " + String(it->moistureSensor.getHwPin()) + "measured_value = " + String(it->moistureSensor.getMeasuredValue()));

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
      it->plant->attemptedWatered();

      if (it->plant->getTimesWatered() < it->plant->getMaxWaterTwoWeeks())
      {
        Serial.println("WATERING " + String((it->plant->getName()).c_str()) + " PLANT!");
        it->plant->plantWatered();
        Serial.println(String((it->plant->getName()).c_str()) + " Has been watered " + String(it->plant->getTimesWatered()) + " times");
        it->motor.motor5s();
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
  Serial.println("------------- 2 Week Results -------------");
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    Serial.println(String((it->plant->getName()).c_str()) + " Has been watered " + String(it->plant->getTimesWatered()) + " times.  Attempted Waters = " + String(it->plant->getTimesAttemptedWatered()));
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

void WateringManager::addPlantSystem(const std::string& plantName, uint8_t moistureSensorPin, uint8_t motorPin)
{
  Plant* plant = PlantFactory::createPlant(plantName);
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