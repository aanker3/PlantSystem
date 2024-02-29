#ifndef MOTOR_H
#define MOTOR_H

#include "../../../helpers.h"
#include "peripheral_base.h"
#include <stdint.h>
#include "Arduino.h"

class Motor : public PeripheralBase {       // The class
  public:             // Access specifier
    Motor(uint8_t pin);
    ~Motor();

    void motor5s();
};


#endif