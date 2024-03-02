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

uint16_t Plant::getMaxWaterTwoWeeks() const {
  return cfg.maxWaterTwoWeeks;
}

void Plant::plantWatered(){
  timesWatered++;
}
uint8_t Plant::getTimesWatered() const {
  return timesWatered;
}

uint8_t Plant::getTimesAttemptedWatered() const {
  return timesAttemptedWatered;
}

void Plant::attemptedWatered()
{
  timesAttemptedWatered++;
}

void Plant::reset(){
  Serial.println("Plant " + String(name.c_str()) + "Resetting");
  timesWatered = 0;
  timesAttemptedWatered = 0;
}