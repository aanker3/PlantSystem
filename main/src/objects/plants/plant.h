#ifndef PLANT_H
#define PLANT_H

#include <cstdint>
#include "plant_config.h"
#include "Arduino.h"

//Plant object
class Plant {
  public:
    Plant(const std::string& plantName, PlantConfig& config);
    ~Plant();

    std::string getName() const;
  
    uint8_t getMoistureSensorPin() const; // Getter for moistureSensorPin

    void setCurrentMoistureValue(float value); // Setter for currentMoistureValue
    float getCurrentMoistureValue() const; // Getter for currentMoistureValue

    float getMoistureWateringPoint() const; // Getter for moistureWateringPoint


    void plantWatered(); // Setter for timesWatered
    int getTimesWatered() const; // Getter for timesWatered
    
    void reset(); //Reset Variables (usually after 50 Day Timeout)
  private:
    // Name of plant
    std::string name;

    //To be set on instantiation
    float moistureWateringPoint;  // Moisture Level at which we should water the plant
    uint16_t waterPerWeek;       // How often plant expects to be watered per week
    uint8_t moistureSensorPin;


    int currentMoistureValue;
    int timesWatered;  // Amount of times plant has been watered

    // Amount of times algorithm determined plant shouldve been watered
    // But didnt due to Max water per week restriction
    int timesAttemptedWatered;
                                

};

#endif