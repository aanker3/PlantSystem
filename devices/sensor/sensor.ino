#include "sensor.h"

#define ADC_MAX 1023.0
#define VOLTAGE_REF 5.0


void setup() {
  Serial.begin(9600);
}

float SensorValueInVoltage(int sensorOutputRead) {
  Serial.println("sensorOutputRead = " + String(sensorOutputRead));
  float voltage = sensorOutputRead * (VOLTAGE_REF / ADC_MAX);
  return voltage;
}


  void loop() {
  float sensor_valueA0 = SensorValueInVoltage(analogRead(A0));
  float sensor_valueA1 = SensorValueInVoltage(analogRead(A1));

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.print("Moisture_Sensor_A0: " + String(sensor_valueA0));
  Serial.print("Moisture_Sensor_A1: " + String(sensor_valueA1));
  delay(1000);  // Delay a bit to make it more readable
}