#include "motor.h"

Motor::Motor(uint8_t pin) : hwPin(pin){
  pinMode(hwPin, OUTPUT);
}

Motor::~Motor(){
  // Turn the motor off
  digitalWrite(hwPin, LOW);
}

void Motor::setHwPin(uint8_t value){
  hwPin = value;
}

uint8_t Motor::getHwPin() const {
  return hwPin;
}

void Motor::motor5s(){
  // Turn the motor off
  digitalWrite(hwPin, HIGH);
  delay(5000);
  digitalWrite(hwPin, LOW);
}