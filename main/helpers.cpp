#include "helpers.h"

//Time ran in ms.
unsigned long GetTimeElapsedMilliseconds(){
  return millis();
}

unsigned long GetTimeElapsedSeconds(){
  return millis() / MILLIS_TO_SECONDS;
}

unsigned long GetTimeElapsedMinutes(){
  return millis() / MILLIS_TO_MINUTES;
}


unsigned long GetTime(unsigned long previousTime)
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;
  return elapsedTime;
}

unsigned long GetTimeAndUpdate(unsigned long &previousTime)
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;

  // Check if elapsedTime has exceeded or is exactly one week,
  // if so, reset previousTime to "simulate" resetting the timer
  if (elapsedTime >= ONE_WEEK)
  {
    previousTime = currentTime - (elapsedTime - ONE_WEEK);
    elapsedTime = 0; // Reset elapsed time to 0
  }

  return elapsedTime;
}