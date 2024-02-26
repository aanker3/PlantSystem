#include "fern_plant.h"

// Constructor - Initialize Variables
FernPlant::FernPlant() {
  reset();
  desiredMoistureValue = 2.0; //Change this
}

FernPlant::~FernPlant(){

}

void FernPlant::setMoistureValue(float value){
  moistureValue = value;
}
float FernPlant::getMoistureValue() const {
  return moistureValue;
}

float FernPlant::getDesiredMoistureValue() const {
  return desiredMoistureValue;
}


void FernPlant::plantWatered(){
  timesWatered++;
}
int FernPlant::getTimesWatered() const {
  return timesWatered;
}

void FernPlant::reset(){
  timesWatered = 0;
}