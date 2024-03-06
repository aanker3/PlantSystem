#include "sensor.h"

Sensor::Sensor(uint8_t pin) : HwPeripheralBase(pin){
}

float Sensor::getMeasuredValue() const{
  return analogRead(hwPin);
}