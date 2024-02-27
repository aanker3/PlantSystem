#include "plant_factory.h"

Plant* PlantFactory::createPlant(const std::string& plant_name)
{
  if (plant_name == "Fern")
  {
    return new Plant(FERN_DESIRED_MOISTURE);
  }
  else if (plant_name == "Cactus")
  {
    return new Plant(CACTUS_DESIRED_MOISTURE);
  }
  else
  {
    Serial.println("Error.  Plant not found");
    //Serial.println("Error.  Plant " + plant_name + "not found");
  }
}

//I dont think i want to do this.