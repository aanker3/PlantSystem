#include "plant_config.h"
#include "Arduino.h"

#define FERN_MOISTURE_WATERING_POINT 270.0f
#define FERN_MAX_WATER_TWO_WEEKS 5

#define CACTUS_MOISTURE_WATERING_POINT 280.5f
#define CACTUS_MAX_WATER_TWO_WEEKS 2

#define BASIL_MOISTURE_WATERING_POINT 266.1f
#define BASIL_MAX_WATER_TWO_WEEKS 4

// Save Plant Configurations in Memory
std::map<std::string, PlantConfig> plantConfigurations = {
    //Name, moistureWateringPoint, maxWaterTwoWeeks
    {"fern", {FERN_MOISTURE_WATERING_POINT, FERN_MAX_WATER_TWO_WEEKS}},
    {"cactus", {CACTUS_MOISTURE_WATERING_POINT, CACTUS_MAX_WATER_TWO_WEEKS}},
    {"basil", {BASIL_MOISTURE_WATERING_POINT, BASIL_MAX_WATER_TWO_WEEKS}},
};
