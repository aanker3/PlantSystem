#include "hw_peripheral_base.h"

HwPeripheralBase::HwPeripheralBase(uint8_t pin) : hwPin(pin){
}

HwPeripheralBase::~HwPeripheralBase(){

}

void HwPeripheralBase::setHwPin(uint8_t value){
  hwPin = value;
}
uint8_t HwPeripheralBase::getHwPin() const {
  return hwPin;
}