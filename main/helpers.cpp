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

/*
unsigned long GetTimeElapsedSince(unsigned long previousTime)
{
  unsigned long currentTime = millis(); // Local to loop(), redeclared each iteration
  unsigned long elapsedTime = currentTime - previousTime;


}
*/