#ifndef HELPERS_H
#define HELPERS_H
#include "Arduino.h"
#include <cstdint>

#define FIVE_SECONDS_MS 5000

#define ADC_MAX 1023.0
#define VOLTAGE_REF 5.0

#define MILLIS_TO_SECONDS 1000
#define MILLIS_TO_MINUTES MILLIS_TO_SECONDS / 60

#define ONE_MINUTE_MS 60000
#define ONE_DAY_MS 5000 //86400000
#define ONE_WEEK_MS ONE_DAY_MS * 7

unsigned long GetTimeElapsedMinutes();

void GetTimeAndUpdate(unsigned long &previousTime, uint16_t &days_elapsed);

#endif