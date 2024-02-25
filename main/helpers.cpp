#include "helpers.h"

#define ADC_MAX 1023.0
#define VOLTAGE_REF 5.0

#define MILLIS_TO_SECONDS 1000
#define MILLIS_TO_MINUTES MILLIS_TO_SECONDS / 60

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