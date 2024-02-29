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
    Serial.println("pin: " + String(it->moistureSensor->getHwPin()) + "measured_value = " + String(it->moistureSensor->getMeasuredValue()));

    Serial.println(it->motor.getHwPin());
    plantNum++;
  }
}

void WateringManager::gatherDataAndWater()
{
    for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
      if (it->plant->getMoistureWateringPoint() > it->moistureSensor->getMeasuredValue())
      {
        Serial.println("WATERING PLANT!");
        it->motor->motor5s();
      }
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
  HwPeripheralBase* moistureSensor = HwPeripheralFactory::createHwPeripheral("MoistureSensor", moistureSensorPin);
  if (!moistureSensor) {
    Serial.println("Error: MoistureSensor creation failed.");
    delete plant; // Clean up previously allocated memory
    return;
  }
  //MoistureSensor moistureSensor = MoistureSensor(moistureSensorPin);
  HwPeripheralBase* motor = HwPeripheralFactory::createHwPeripheral("Motor", motorPin);
  if (!motor) {
    Serial.println("Error: Motor creation failed.");
    delete plant; // Clean up
    delete moistureSensor; // Clean up
    return;
  }
  
  PlantSystem newPlantSystem = {plant, moistureSensor, motor};
  plantSystems.push_back(newPlantSystem);
}