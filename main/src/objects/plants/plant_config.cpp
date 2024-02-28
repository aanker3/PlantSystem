#include "plant_config.h"
#include "Arduino.h"

// Global or static storage for configurations
std::map<std::string, PlantConfig> plantConfigurations = {
    //Name, moistureWateringPoint, waterPerWeek, moisturesensor_pin
    {"fern", {2, 5, A0}},
    {"cactus", {1.5, 2, A0}},
};
