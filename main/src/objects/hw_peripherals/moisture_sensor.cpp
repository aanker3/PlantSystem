#include "moisture_sensor.h"

MoistureSensor::MoistureSensor(uint8_t pin) : PeripheralBase(pin){
}

float MoistureSensor::getMeasuredValue() const{
  return SensorValueInVoltage(analogRead(hwPin));
}