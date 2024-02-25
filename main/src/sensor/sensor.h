#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>
#include "Arduino.h"
#include "../../sensor_conversions.h"

class Sensor {       // The class
  public:             // Access specifier
    Sensor(uint8_t pin);
    ~Sensor();

    void setHwPin(uint8_t pin); // Setter for pin
    uint8_t getHwPin() const; // Getter for moistureValue

    float getMeasuredValue();

  private:
    uint8_t hwPin;        // Attribute (int variable)
    float measuredValue;
};


#endif