#ifndef WATERING_MANAGER_H
#define WATERING_MANAGER_H

#include "hw_peripherals/sensor.h"
#include "hw_peripherals/motor.h"
#include "plants/plant.h"
#include "plants/plant_factory.h"
#include "../helpers/wateringEquations.h"
#include <vector>

// Consists of everything that makes up a single plant system
struct  PlantSystem {
  Plant* plant;
  Sensor moistureSensor;
  Motor motor;
};

class WateringManager {
  public:

    WateringManager(uint8_t weightSensorPin);
    ~WateringManager();

    void addPlantSystem(const std::string& plantName, PotSize potSize, uint8_t moistureSensorPin, uint8_t motorPin);

    void printPlantSystemsInfo() const;
  
    void gatherSensorData();

    void wateringDelay(uint16_t amountToWater);

    void waterPlantsIfNeeded();

    void printTwoWeekResults(uint16_t weeksElapsed);

    void resetPlants();

  private:
  std::vector<PlantSystem> plantSystems;
  Sensor weightSensor;

};
#endif