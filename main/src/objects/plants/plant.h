#ifndef PLANT_H
#define PLANT_H

#include <cstdint>
#include "plant_config.h"
#include "Arduino.h"

//Plant object
class Plant {
  public:
    Plant(const std::string& plantName, PotSize potSize, PlantConfig& config);
    ~Plant();

    std::string getName() const;
  
    void setCurrentMoistureValue(float value); // Setter for currentMoistureValue
    float getCurrentMoistureValue() const; // Getter for currentMoistureValue

    float getMoistureWateringPoint() const; // Getter for moistureWateringPoint

    uint16_t getmaxWaterWeekly() const;

    PotSize getPotSize() const;


    //TODO: can simply do a getCfg()? Do i want this?


    void plantWatered(); // Setter for timesWatered
    uint8_t getTimesWatered() const; // Getter for timesWatered
    
    void reset(); //Reset Variables (after timeout)
  private:
    // Name of plant
    std::string name;

    //Cfg To be set on instantiation
    PlantConfig cfg;

    float currentMoistureValue;

    uint8_t timesWatered;  // Amount of times plant has been watered

    PotSize potSize;
                                

};

#endif