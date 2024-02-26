#include "moisture_sensor.h"

MoistureSensor::MoistureSensor(uint8_t pin) : Sensor(pin){
}

float MoistureSensor::getMeasuredValue(){
  measuredValue = SensorValueInVoltage(analogRead(hwPin));
  return measuredValue;
}