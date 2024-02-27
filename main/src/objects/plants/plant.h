#ifndef PLANT_H
#define PLANT_H

//include "sensor.h"
#define FERN_DESIRED_MOISTURE 2.0f
#define CACTUS_DESIRED_MOISTURE 1.5f

//Plant object
class Plant {
  public:
    Plant(float desiredMoisture);;
    ~Plant();

    void setMoistureValue(float value); // Setter for moistureValue
    float getMoistureValue() const; // Getter for moistureValue

    float getDesiredMoistureValue() const; // Getter for desiredMoistureValue

    void plantWatered(); // Setter for timesWatered
    int getTimesWatered() const; // Getter for timesWatered
    
    void reset(); //Reset Variables (usually after 50 Day Timeout)
  private:
    int moistureValue;
    int timesWatered;  // Amount of times plant has been watered
    float desiredMoistureValue;

};

#endif