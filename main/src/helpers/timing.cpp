#include "timing.h"

unsigned long msToMinutes(unsigned long ms){
  return millis() / MILLIS_TO_MINUTES;
}

void getTimeAndUpdate(unsigned long &previousTime, uint16_t &days_elapsed)
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;
  Serial.println("Minutes Elapsed = " + String(msToMinutes(elapsedTime)));
  // Check if elapsedTime has exceeded or is exactly one week,
  // if so, reset previousTime to "simulate" resetting the timer
  if (elapsedTime >= ONE_DAY_MS)
  {
    previousTime = currentTime - (elapsedTime - ONE_DAY_MS);
    days_elapsed++;
  }
}

bool twoWeeksElapsed(uint16_t &days_elapsed) {
  if (days_elapsed >= 14) {
    days_elapsed = 0; // Reset the days elapsed to start counting a new period
    return true; // Two weeks have elapsed
  }
  return false; // Less than two weeks have passed
}