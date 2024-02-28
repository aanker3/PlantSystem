#include "device_manager.h"
#include "Arduino.h"

// Constructor - Initialize Variables
DeviceManager::DeviceManager(Plant& plant, MoistureSensor& moistureSensor) : plant(plant), moistureSensor(moistureSensor)
{
}

DeviceManager::~DeviceManager(){

}

std::string DeviceManager::getPlantName() const {
  return plant.getName();
}