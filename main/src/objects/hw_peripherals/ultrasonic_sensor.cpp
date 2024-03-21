#include "ultrasonic_sensor.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(uint8_t rxPin, uint8_t txPin) : rxHwPin(rxPin), txHwPin(txPin){
  // Set the Trig and Echo pins
  pinMode(rxHwPin, OUTPUT);
  pinMode(txHwPin, INPUT);
}

unsigned long UltrasonicSensor::getAccurateMeasuredValue() const{
  // Use median of 5 readings
  unsigned long readings[READINGS_TO_COLLECT_PER_MEASUREMENT];

  //Get Readings Values
  for (int i = 0; i<READINGS_TO_COLLECT_PER_MEASUREMENT; i++)
  {
    readings[i]=getMeasuredValue();
    delay(100);

  }

  
  Serial.println("individual readings = ");
  for(int i = 0; i < READINGS_TO_COLLECT_PER_MEASUREMENT; i++) {
      Serial.println("reading[" + String(i) + "] = " + String(readings[i]));
  }

  insertionSort(readings, READINGS_TO_COLLECT_PER_MEASUREMENT);

  return readings[MEDIAN_READING];
}


unsigned long UltrasonicSensor::getMeasuredValue() const{
  // Clear the Trig pin
  digitalWrite(rxHwPin, LOW);
  delayMicroseconds(2);
  
  // Set the Trig pin on HIGH state for 10 micro seconds
  digitalWrite(rxHwPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(rxHwPin, LOW);
  
  // Read the Echo pin; pulseIn returns the duration (length of the pulse) in microseconds
  unsigned long duration = pulseIn(txHwPin, HIGH);
  
  // Calculate the distance
  unsigned long distance = duration * SPEED_OF_LIGHT_MM_PER_USEC / 2; // Speed of sound wave divided by 2 (tx and rx)

  return distance;
}