#ifndef PLANT_H
#define PLANT_H

//include "sensor.h"

class Plant {       // The class
  public:             // Access specifier
    Plant();
    ~Plant();

    void setMoistureValue(float value); // Setter for moistureValue
    float getMoistureValue(); // Getter for moistureValue
  private:
    float moistureValue;        // Attribute (int variable)

};

#endif