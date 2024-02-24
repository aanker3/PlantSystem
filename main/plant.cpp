#include "plant.h"

// Constructor - Initialize Variables
Plant::Plant() {
  reset();
  desiredMoistureValue = 2.0; //Change this
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