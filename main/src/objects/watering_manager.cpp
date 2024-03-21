#include "watering_manager.h"
#include "Arduino.h"

// Constructor - Initialize Variables
WateringManager::WateringManager(UltrasonicSensor& ultrasonicSensor_instance): ultrasonicSensor(ultrasonicSensor_instance){
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
      if (it->plant->getTimesWatered() < it->plant->getMaxWaterWeekly())
      {
        Serial.println("WATERING " + String((it->plant->getName()).c_str()) + " PLANT!");
        it->plant->plantWatered();
        Serial.println(String((it->plant->getName()).c_str()) + " Has been watered " + String(it->plant->getTimesWatered()) + " times");
        
        unsigned long wateringAmount = getWateringAmount(it->plant->getPotSize());
        Serial.println("Watering" + String(wateringAmount) + " Milliliters");
        unsigned long initialWaterLevel = ultrasonicSensor.getAccurateMeasuredValue();
        it->motor.turnOn();
        unsigned long currentWaterLevel = initialWaterLevel;
        while(currentWaterLevel < initialWaterLevel + wateringAmount)
        {
          currentWaterLevel = ultrasonicSensor.getAccurateMeasuredValue();
          Serial.println("CURRENT WATERING LEVEL = " + String(currentWaterLevel) + " Milliliters");

        }

        Serial.println("BEFORE Watering LEVEL" + String(initialWaterLevel) + " Milliliters");
        Serial.println("Ideal Watering Difference = " + String(wateringAmount) + "Milliliters.  Actual watering Difference = " + String(currentWaterLevel - initialWaterLevel));

        Serial.println("AFTER Watering LEVEL" + String(currentWaterLevel) + " Milliliters");


        
        //Delay = blocking function w/ weight sensor
        //delay(wateringTime);
        it->motor.turnOff();
      }
      else
      {
        Serial.println("Plant " + String((it->plant->getName()).c_str()) + " Watered TOO MANY TIMES!");
      }
    }
  }
}

void WateringManager::printWeeklyResults(uint16_t weeksElapsed)
{
  //todo Log output to sd card.
  Serial.println("------------- Week" + String(weeksElapsed+1)+ " Results -------------");
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    Serial.println(String((it->plant->getName()).c_str()) + " Has been watered " + String(it->plant->getTimesWatered()) + " times.  MAX Water per week = " + String(it->plant->getMaxWaterWeekly()));
  }
  Serial.println("------------- -------------- -------------");
}

void WateringManager::resetPlants()
{
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