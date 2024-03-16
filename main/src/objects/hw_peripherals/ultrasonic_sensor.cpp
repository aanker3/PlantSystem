#include "ultrasonic_sensor.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(uint8_t rxPin, uint8_t txPin) : rxHwPin(rxPin), txHwPin(txPin){
  // Set the Trig and Echo pins
  pinMode(rxHwPin, OUTPUT);
  pinMode(txHwPin, INPUT);
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
  unsigned long distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and return)

  return distance;
}