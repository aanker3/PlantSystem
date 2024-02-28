#include "watering_manager.h"
#include "Arduino.h"

// Constructor - Initialize Variables
WateringManager::WateringManager(){
}

WateringManager::~WateringManager(){

}

void WateringManager::printSystemsInfo() const {
  for(auto it = plantSystems.begin(); it != plantSystems.end(); ++it) {
    Serial.println((it->plant.getName()).c_str());
  }
}

void WateringManager::AddPlant(Plant& plant, MoistureSensor& moistureSensor)
{
  PlantSystem newPlant = {plant, moistureSensor};
  plantSystems.push_back(newPlant);
}