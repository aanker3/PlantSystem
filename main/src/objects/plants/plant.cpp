#include "plant.h"
#include "Arduino.h"

// Constructor - Initialize Variables
Plant::Plant(float desiredMoisture): desiredMoistureValue(desiredMoisture) {
  reset();
}

Plant::~Plant(){

}

void Plant::setMoistureValue(float value){
  Serial.println("Plant::setMoistureValue");
  moistureValue = value;
}
float Plant::getMoistureValue() const {
  Serial.println("Plant::getMoistureValue");
  return moistureValue;
}

float Plant::getDesiredMoistureValue() const {
  Serial.println("Plant::getDesiredMoistureValue");

  return desiredMoistureValue;
}


void Plant::plantWatered(){
  Serial.println("Plant::getDesiredMoistureValue");
  timesWatered++;
}
int Plant::getTimesWatered() const {
  Serial.println("Plant::getTimesWatered");
  return timesWatered;
}

void Plant::reset(){
  timesWatered = 0;
}