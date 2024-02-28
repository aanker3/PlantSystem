#ifndef PLANT_CONFIG_H
#define PLANT_CONFIG_H

#include <map>

struct PlantConfig {
    float moistureWateringPoint;
    uint16_t waterPerWeek;
    uint8_t moistureSensorPin;
};

// Declaration only
extern std::map<std::string, PlantConfig> plantConfigurations;

#endif