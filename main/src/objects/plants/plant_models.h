#ifndef PLANT_MODELS_H
#define PLANT_MODELS_H

#include "plant.h"

#define FERN_DESIRED_MOISTURE_VALUE 2.0f


//Plant object
class FernPlant : public Plant {
  public:
    FernPlant();
    ~FernPlant();
};

#endif