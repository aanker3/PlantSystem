#ifndef WATERING_MANAGER_H
#define WATERING_MANAGER_H

#include "hw_peripherals/moisture_sensor.h"
#include "hw_peripherals/motor.h"
#include "plants/plant.h"
#include "plants/plant_factory.h"
#include "../helpers/wateringEquations.h"
#include <vector>

// Consists of everything that makes up a single plant system
struct  PlantSystem {
  Plant* plant;
  MoistureSensor moistureSensor;
  Motor motor;
};

class WateringManager {
  public:

    WateringManager();
    ~WateringManager();

    void addPlantSystem(const std::string& plantName, PotSize potSize, uint8_t moistureSensorPin, uint8_t motorPin);

    void printPlantSystemsInfo() const;
  
    void gatherSensorData();

    void waterPlantsIfNeeded();

    void printWeeklyResults(uint16_t weeksElapsed);

    void resetPlants();

  private:
  std::vector<PlantSystem> plantSystems;


};
#endif