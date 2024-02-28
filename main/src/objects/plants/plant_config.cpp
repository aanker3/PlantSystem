#include "plant_config.h"
#include "Arduino.h"

#define FERN_MOISTURE_WATERING_POINT 2
#define FERN_WATER_PER_WEEK 5

#define CACTUS_MOISTURE_WATERING_POINT 1.5f
#define CACTUS_WATER_PER_WEEK 2

// Save Plant Configurations in Memory
std::map<std::string, PlantConfig> plantConfigurations = {
    //Name, moistureWateringPoint, waterPerWeek
    {"fern", {FERN_MOISTURE_WATERING_POINT, FERN_WATER_PER_WEEK}},
    {"cactus", {CACTUS_MOISTURE_WATERING_POINT, CACTUS_WATER_PER_WEEK}},
};
