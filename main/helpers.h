#ifndef HELPERS_H
#define HELPERS_H
#include "Arduino.h"
#include <cstdint>

#define FIVE_SECONDS_MS 5000

#define ADC_MAX 1023.0
#define VOLTAGE_REF 5.0

#define MILLIS_TO_SECONDS 1000
#define MILLIS_TO_MINUTES MILLIS_TO_SECONDS / 60

unsigned long GetTimeElapsedMilliseconds();

unsigned long GetTimeElapsedSeconds();

unsigned long GetTimeElapsedMinutes();


#endif