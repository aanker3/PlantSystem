#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H

#include "plant.h"
#include <string>
#include "Arduino.h"

class PlantFactory {       // The class
  public:             // Access specifier
    //Static so it can be called directly, outside the class
    static Plant* createPlant(const std::string& plantName);
};


#endif