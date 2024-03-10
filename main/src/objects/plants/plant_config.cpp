#include "plant_config.h"
#include "Arduino.h"

#define FERN_MOISTURE_WATERING_POINT 270.0f
#define FERN_MAX_WATER_ONE_WEEK 5

#define CACTUS_MOISTURE_WATERING_POINT 280.5f
#define CACTUS_MAX_WATER_ONE_WEEK 2

#define BASIL_MOISTURE_WATERING_POINT 266.1f
#define BASIL_MAX_WATER_ONE_WEEK 4

// Save Plant Configurations in Memory
std::map<std::string, PlantConfig> plantConfigurations = {
    //Name, moistureWateringPoint, maxWaterWeekly
    {"fern", {FERN_MOISTURE_WATERING_POINT, FERN_MAX_WATER_ONE_WEEK}},
    {"cactus", {CACTUS_MOISTURE_WATERING_POINT, CACTUS_MAX_WATER_ONE_WEEK}},
    {"basil", {BASIL_MOISTURE_WATERING_POINT, BASIL_MAX_WATER_ONE_WEEK}},
};
