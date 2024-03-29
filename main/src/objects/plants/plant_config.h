#ifndef PLANT_CONFIG_H
#define PLANT_CONFIG_H

#include <map>

struct PlantConfig {
    float moistureWateringPoint;
    uint16_t maxWaterWeekly;
};

enum PotSize {
    Small,
    Medium,
    Large
};

// Declaration only
extern std::map<std::string, PlantConfig> plantConfigurations;

#endif