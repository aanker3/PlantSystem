#ifndef PERIPHERAL_BASE_H
#define PERIPHERAL_BASE_H

#include <stdint.h>

//Abstract Based Peripheral Class.
//Handles Peripheral HW Initialization
class HwPeripheralBase {       // The class
  public:             // Access specifier
    HwPeripheralBase(uint8_t pin);
    virtual ~HwPeripheralBase();

    virtual void setHwPin(uint8_t pin); // Setter for hwPin
    virtual uint8_t getHwPin() const; // Getter for hwPin

  protected:
    uint8_t hwPin;        // Attribute (int variable)
};


#endif