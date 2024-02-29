#include "peripheral_base.h"

PeripheralBase::PeripheralBase(uint8_t pin) : hwPin(pin){
}

PeripheralBase::~PeripheralBase(){

}

void PeripheralBase::setHwPin(uint8_t value){
  hwPin = value;
}
uint8_t PeripheralBase::getHwPin() const {
  return hwPin;
}