#ifndef MOTOR_H
#define MOTOR_H

#include "helpers.h"
#include <stdint.h>
#include "Arduino.h"

class Motor {       // The class
  public:             // Access specifier
    Motor(uint8_t pin);
    ~Motor();

    void setHwPin(uint8_t pin); // Setter for pin
    uint8_t getHwPin() const; // Getter for moistureValue

    void motor5s();

  private:
    uint8_t hwPin;        // Attribute (int variable)
};


#endif