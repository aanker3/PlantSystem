#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <stdint.h>
#include "Arduino.h"
#include "../../helpers/sorting.h"

#define SPEED_OF_LIGHT_MM_PER_USEC .343
#define FULL_BOTTLE_DISTANCE_MM 30
#define EMPTY_BOTTLE_DISTANCE_MM 150
#define ONE_FLUID_OUNCE_MM 2

//1 MM =
/*
01577 Liters
Gallons: 0.00417
Quarts: 0.01666
Pints: 0.03333
Cups: 0.06666
Fluid ounces: 0.53325  <--- Lets use this. and round to .5
Milliliters: 15.77
*/

//Must be even
#define READINGS_TO_COLLECT_PER_MEASUREMENT 20
#define MEDIAN_READING (READINGS_TO_COLLECT_PER_MEASUREMENT / 2)

//Means 13cm = half a gallon.

class UltrasonicSensor {
  public:
    UltrasonicSensor(uint8_t rxHwPin, uint8_t txHwPin);
    unsigned long getMeasuredValue() const;
    unsigned long getAccurateMeasuredValue() const;

  private:
    unsigned long measuredValue;

    uint8_t rxHwPin;
    uint8_t txHwPin;
};


#endif