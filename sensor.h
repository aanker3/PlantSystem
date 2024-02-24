#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

class Sensor {       // The class
  public:             // Access specifier
    Sensor(uint8_t dio);
    ~Sensor();

    void setSensorDio(uint8_t dio); // Setter for moistureValue
    uint8_t getSensorDio(); // Getter for moistureValue
  private:
    uint8_t dio_value;        // Attribute (int variable)
    float measured_value;

};


#endif