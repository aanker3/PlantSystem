#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>
#include "Arduino.h"
#include "hw_peripheral_base.h"

class Sensor : public HwPeripheralBase {
  public:
    Sensor(uint8_t pin);
    float getMeasuredValue() const;

  private:
    float measuredValue;
};


#endif