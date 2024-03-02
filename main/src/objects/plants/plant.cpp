#include "plant.h"
#include "Arduino.h"

// Constructor - Initialize Variables
Plant::Plant(const std::string& plantName, PlantConfig& config) : name(plantName), cfg(config)
{
  reset();
}

Plant::~Plant(){

}

std::string Plant::getName() const {
  return name;
}

void Plant::setCurrentMoistureValue(float value){
  currentMoistureValue = value;
}
float Plant::getCurrentMoistureValue() const {
  return currentMoistureValue;
}

float Plant::getMoistureWateringPoint() const {
  return cfg.moistureWateringPoint;
}


void Plant::plantWatered(){
  timesWatered++;
}
uint8_t Plant::getTimesWatered() const {
  return timesWatered;
}

void Plant::reset(){
  timesWatered = 0;
  timesAttemptedWatered = 0;
}