#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

#include <stdint.h>
#include "Arduino.h"
#include "hw_peripheral_base.h"

class MoistureSensor : public HwPeripheralBase {
  public:
    MoistureSensor(uint8_t pin);
    float getMeasuredValue() const;

  private:
    float measuredValue;
};


#endif