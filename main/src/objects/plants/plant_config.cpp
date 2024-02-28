#include "plant_config.h"

// Global or static storage for configurations
std::map<std::string, PlantConfig> plantConfigurations = {
    //Name, moistureWateringPoint, waterPerWeek
    {"fern", {2, 5}},
    {"cactus", {1.5, 2}},
};
