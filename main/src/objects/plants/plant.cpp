#include "plant.h"
#include "Arduino.h"

// Constructor - Initialize Variables
Plant::Plant(const std::string& plantName, PotSize potSize, PlantConfig& config) : name(plantName), potSize(potSize), cfg(config)
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

uint16_t Plant::getMaxWaterWeekly() const {
  return cfg.maxWaterWeekly;
}

PotSize Plant::getPotSize() const {
  return potSize;
}


void Plant::plantWatered(){
  timesWatered++;
}

uint8_t Plant::getTimesWatered() const {
  return timesWatered;
}

void Plant::reset(){
  Serial.println("Plant " + String(name.c_str()) + "Resetting");
  timesWatered = 0;
}