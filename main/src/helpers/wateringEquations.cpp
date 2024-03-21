#include "wateringEquations.h"


//Amount of time to water a plant
unsigned long getWateringAmount(PotSize potSize)
{
  switch(potSize)
  {
    case PotSize::Small:
      return 3;
    case PotSize::Medium:
      return 5;
    case PotSize::Large:
      return 7;
  }
}