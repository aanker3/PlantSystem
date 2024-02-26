#ifndef FERN_PLANT_H
#define FERN_PLANT_H

//include "sensor.h"

//Plant object
class FernPlant {
  public:
    FernPlant();
    ~FernPlant();

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