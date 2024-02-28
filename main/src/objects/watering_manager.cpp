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
    Serial.println(it->moistureSensor.getHwPin());
    plantNum++;
  }
}

void WateringManager::addPlantSystem(const std::string& plantName, uint8_t moistureSensorPin)
{
  Plant* plant = PlantFactory::createPlant(plantName);
  if (plant==NULL)
  {
    Serial.println("Error Plant is NULL.  Plant name not found");
    return;
  }
  MoistureSensor moistureSensor = MoistureSensor(moistureSensorPin);
  PlantSystem newPlant = {plant, moistureSensor};
  plantSystems.push_back(newPlant);
}