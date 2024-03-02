#include "plant_factory.h"

Plant* PlantFactory::createPlant(const std::string& plantName, PotSize potSize)
{
    auto it = plantConfigurations.find(plantName);
    if (it != plantConfigurations.end()) {
        return new Plant(plantName, potSize, it->second);
    } else {
        return nullptr;
    }
}