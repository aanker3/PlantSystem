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

    uint8_t getTimesAttemptedWatered() const;
    void attemptedWatered();

    uint16_t getMaxWaterTwoWeeks() const;

    PotSize getPotSize() const;


    //TODO: can simply do a getCfg()...


    void plantWatered(); // Setter for timesWatered
    uint8_t getTimesWatered() const; // Getter for timesWatered
    
    void reset(); //Reset Variables (usually after 50 Day Timeout)
  private:
    // Name of plant
    std::string name;

    //Cfg To be set on instantiation
    PlantConfig cfg;

    float currentMoistureValue;
    
    uint8_t timesWatered;  // Amount of times plant has been watered

    // Amount of times algorithm determined plant shouldve been watered
    // But didnt due to Max water per week restriction
    uint8_t timesAttemptedWatered;

    PotSize potSize;
                                

};

#endif