#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include "sensors/moisture_sensor.h"
#include "plants/plant.h"

class DeviceManager {
  public:
    DeviceManager(Plant& plant, MoistureSensor& moistureSensor);
    ~DeviceManager();

    std::string getPlantName() const;

  private:
  Plant plant;
  MoistureSensor moistureSensor;
};

#endif