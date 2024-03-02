#ifndef TIMING_H
#define TIMING_H
#include "Arduino.h"
#include <cstdint>

#define MILLIS_TO_SECONDS 1000
#define MILLIS_TO_MINUTES MILLIS_TO_SECONDS / 60

#define ONE_MINUTE_MS 60000
#define ONE_DAY_MS 5000//86400000

#define DAYS_IN_A_WEEK 14

unsigned long GetTimeElapsedMinutes();

void getTimeAndUpdate(unsigned long &previousTime, uint16_t &days_elapsed);

bool twoWeeksElapsed(uint16_t &days_elapsed);

#endif