#include "timing.h"

void getTimeAndUpdateDaysElapsed(unsigned long &previousTime, uint16_t &daysElapsed)
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;
  //Serial.println("Minutes Elapsed = " + String(msToMinutes(elapsedTime)));
  // Days elapsed counter
  if (elapsedTime >= ONE_DAY_MS)
  {
    previousTime = currentTime - (elapsedTime - ONE_DAY_MS);
    daysElapsed++;
  }
}

bool weekElapsed(uint16_t &daysElapsed) {
  if (daysElapsed >= DAYS_IN_A_WEEK) {
     // Reset the days elapsed to start counting a new period
    daysElapsed = 0;
    return true; // One week has elapsed
  }
  return false; // Less than one week has passed
}