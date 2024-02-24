#include "sensor.h"

Sensor::Sensor(uint8_t pin) : hwPin(pin){
}

Sensor::~Sensor(){

}

void Sensor::setHwPin(uint8_t value){
  hwPin = value;
}
uint8_t Sensor::getHwPin() const {
  return hwPin;
}

float Sensor::getMeasuredValue(){
  measuredValue = SensorValueInVoltage(analogRead(hwPin));
  return measuredValue;
}
