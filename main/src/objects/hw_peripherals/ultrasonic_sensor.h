#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <stdint.h>
#include "Arduino.h"

#define SPEED_OF_LIGHT_CM_PER_USEC .0343

class UltrasonicSensor {
  public:
    UltrasonicSensor(uint8_t rxHwPin, uint8_t txHwPin);
    unsigned long getMeasuredValue() const;

  private:
    unsigned long measuredValue;

    uint8_t rxHwPin;
    uint8_t txHwPin;
};


#endif