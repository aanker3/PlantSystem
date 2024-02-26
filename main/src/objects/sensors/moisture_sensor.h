#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

#include <stdint.h>
#include "Arduino.h"
#include "sensor.h"
#include "../../../sensor_conversions.h"

class MoistureSensor : public Sensor {       // The class
  public:             // Access specifier
    MoistureSensor(uint8_t pin);
    float getMeasuredValue();

  private:
    float measuredValue;
};


#endif