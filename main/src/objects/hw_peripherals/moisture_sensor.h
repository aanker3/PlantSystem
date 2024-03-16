#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

#include <stdint.h>
#include "Arduino.h"

class MoistureSensor {
  public:
    MoistureSensor(uint8_t pin);
    
    float getMeasuredValue() const;

    uint8_t getHwPin() const; // Getter for hwPin

  private:
    uint8_t hwPin;
    float measuredValue;
};


#endif