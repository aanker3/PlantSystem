#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "Arduino.h"

class Motor {
  public:
    Motor(uint8_t pin);
    ~Motor();

    void motor5s();

    void turnOn();

    void turnOff();

    uint8_t getHwPin() const; // Getter for hwPin

  private:

    uint8_t hwPin;

};


#endif