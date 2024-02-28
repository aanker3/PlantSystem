#ifndef WATERING_MANAGER_H
#define WATERING_MANAGER_H

#include "sensors/moisture_sensor.h"
#include "plants/plant.h"
#include <vector>
// Consists of everything that makes up a single plant system
struct  PlantSystem {
  Plant plant;
  MoistureSensor moistureSensor;
};

class WateringManager {
  public:

    WateringManager();
    ~WateringManager();

    void AddPlant(Plant& plant, MoistureSensor& moistureSensor);

    void printSystemsInfo() const;

  private:
  std::vector<PlantSystem> plantSystems;


};
#endif