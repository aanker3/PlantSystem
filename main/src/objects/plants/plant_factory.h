#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H

#include "plant.h"
#include <string>
#include "Arduino.h"

//Abstract Based Sensor Class.
//Handles Sensor HW Initialization
class PlantFactory {       // The class
  public:             // Access specifier
    static Plant* createPlant(const std::string& plantName);
};


#endif