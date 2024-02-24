#include "sensor_conversions.h"

#define ADC_MAX 1023.0
#define VOLTAGE_REF 5.0

float SensorValueInVoltage(int sensorOutputRead) {
  //Serial.print("sensorOutputRead = " + String(sensorOutputRead));
  float voltage = sensorOutputRead * (VOLTAGE_REF / ADC_MAX);
  return voltage;
}