#include "plant.h"

// Constructor - Initialize Variables
Plant::Plant(float desiredMoisture) : desiredMoistureValue(desiredMoisture) {
  reset();
}

Plant::~Plant(){

}

void Plant::setMoistureValue(float value){
  moistureValue = value;
}
float Plant::getMoistureValue() const {
  return moistureValue;
}

float Plant::getDesiredMoistureValue() const {
  return desiredMoistureValue;
}


void Plant::plantWatered(){
  timesWatered++;
}
int Plant::getTimesWatered() const {
  return timesWatered;
}

void Plant::reset(){
  timesWatered = 0;
}