#include "plant_factory.h"

Plant* PlantFactory::createPlant(const std::string& plantName)
{
    auto it = plantConfigurations.find(plantName);
    if (it != plantConfigurations.end()) {
        return new Plant(plantName, it->second);
    } else {
        return nullptr;
    }
}