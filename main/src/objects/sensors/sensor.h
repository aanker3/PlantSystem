#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

//Abstract Based Sensor Class.
//Handles Sensor HW Initialization
class Sensor {       // The class
  public:             // Access specifier
    Sensor(uint8_t pin);
    virtual ~Sensor();

    virtual void setHwPin(uint8_t pin); // Setter for pin
    virtual uint8_t getHwPin() const; // Getter for moistureValue

  protected:
    uint8_t hwPin;        // Attribute (int variable)
};


#endif