#include "plant_config.h"
#include "Arduino.h"

#define FERN_MOISTURE_WATERING_POINT 270.0f
#define FERN_WATER_PER_WEEK 5

#define CACTUS_MOISTURE_WATERING_POINT 280.5f
#define CACTUS_WATER_PER_WEEK 2

#define BASIL_MOISTURE_WATERING_POINT 266.1f
#define BASIL_WATER_PER_WEEK 4

// Save Plant Configurations in Memory
std::map<std::string, PlantConfig> plantConfigurations = {
    //Name, moistureWateringPoint, waterPerWeek
    {"fern", {FERN_MOISTURE_WATERING_POINT, FERN_WATER_PER_WEEK}},
    {"cactus", {CACTUS_MOISTURE_WATERING_POINT, CACTUS_WATER_PER_WEEK}},
    {"basil", {BASIL_MOISTURE_WATERING_POINT, BASIL_WATER_PER_WEEK}},
};
