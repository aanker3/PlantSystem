#include "moisture_sensor.h"

MoistureSensor::MoistureSensor(uint8_t pin) : HwPeripheralBase(pin){
}

float MoistureSensor::getMeasuredValue() const{
  return SensorValueInVoltage(analogRead(hwPin));
}