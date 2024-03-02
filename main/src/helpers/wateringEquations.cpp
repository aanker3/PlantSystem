#include "wateringEquations.h"

#define FIVE_SECONDS 5000ul
#define TEN_SECONDS 10000ul
#define FIFTEEN_SECONDS 15000ul

//Amount of time to water a plant
unsigned long getWaterTime(PotSize potSize)
{
  switch(potSize)
  {
    case PotSize::Small:
      return FIVE_SECONDS;
    case PotSize::Medium:
      return TEN_SECONDS;
    case PotSize::Large:
      return FIFTEEN_SECONDS;
  }
}