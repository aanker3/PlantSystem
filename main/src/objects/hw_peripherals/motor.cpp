#include "motor.h"

Motor::Motor(uint8_t pin) : HwPeripheralBase(pin){
  pinMode(hwPin, OUTPUT);
}

Motor::~Motor(){
  // Turn the motor off
  digitalWrite(hwPin, LOW);
}

void Motor::motor5s(){
  // Turn the motor off
  digitalWrite(hwPin, HIGH);
  delay(5000);
  digitalWrite(hwPin, LOW);
}