#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

#include <stdint.h>
#include "Arduino.h"
#include "peripheral_base.h"
#include "../../../sensor_conversions.h"

class MoistureSensor : public PeripheralBase {       // The class
  public:             // Access specifier
    MoistureSensor(uint8_t pin);
    float getMeasuredValue();

  private:
    float measuredValue;
};


#endif