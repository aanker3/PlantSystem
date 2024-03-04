#include "plant_factory.h"

Plant* PlantFactory::createPlant(const std::string& plantName, PotSize potSize)
{
    auto it = plantConfigurations.find(plantName);
    if (it != plantConfigurations.end()) {
        return new Plant(plantName, potSize, it->second);
    } else {
        //add a print here for err  Maybe notify user a different way.
        return NULL;
    }
}