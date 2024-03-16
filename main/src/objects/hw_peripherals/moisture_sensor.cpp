#include "moisture_sensor.h"

MoistureSensor::MoistureSensor(uint8_t pin) : hwPin(pin) {
}

float MoistureSensor::getMeasuredValue() const{
  return analogRead(hwPin);
}

uint8_t MoistureSensor::getHwPin() const {
  return hwPin;
}