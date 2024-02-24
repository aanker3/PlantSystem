#include "plant.h"

Plant::Plant(){

}

Plant::~Plant(){

}

void Plant::setMoistureValue(float value){
  moistureValue = value;
}
float Plant::getMoistureValue() {
  return moistureValue;
}