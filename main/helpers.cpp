#include "helpers.h"

unsigned long GetTimeElapsedMinutes(){
  return millis() / MILLIS_TO_MINUTES;
}


unsigned long GetTime(unsigned long previousTime)
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;
  return elapsedTime;
}

void GetTimeAndUpdate(unsigned long &previousTime, uint16_t &days_elapsed)
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;

  // Check if elapsedTime has exceeded or is exactly one week,
  // if so, reset previousTime to "simulate" resetting the timer
  if (elapsedTime >= ONE_DAY_MS)
  {
    previousTime = currentTime - (elapsedTime - ONE_DAY_MS);
    days_elapsed++;
  }
}