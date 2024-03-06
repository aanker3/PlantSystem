#ifndef PERIPHERAL_BASE_H
#define PERIPHERAL_BASE_H

#include <stdint.h>

//Abstract Based HW Peripheral Class.
class HwPeripheralBase {       // The class
  public:
    HwPeripheralBase(uint8_t pin);
    virtual ~HwPeripheralBase();

    virtual void setHwPin(uint8_t pin); // Setter for hwPin
    virtual uint8_t getHwPin() const; // Getter for hwPin

  protected:
    uint8_t hwPin;
};


#endif