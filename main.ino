#include "sensor.h"
#include "plant.h"

#define ADC_MAX 1023.0
#define VOLTAGE_REF 5.0

const int motorPin = 13; // Adjust this pin according to your setup
Plant fern;
Sensor Moisture(A0);

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);

  //Setup Plants
  fern.setMoistureValue(2.0);
}

float SensorValueInVoltage(int sensorOutputRead) {
  Serial.println("sensorOutputRead = " + String(sensorOutputRead));
  float voltage = sensorOutputRead * (VOLTAGE_REF / ADC_MAX);
  return voltage;
}


  void loop() {
  float sensor_valueA0 = SensorValueInVoltage(analogRead(A0));

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.print("Moisture_Sensor_A0: " + String(sensor_valueA0));

  if(sensor_valueA0 < fern.getMoistureValue())
  {
    Serial.print("WATERING!!! SENSOR_VALUE = " + String(sensor_valueA0));

    digitalWrite(motorPin, HIGH); // Turn the motor on
    delay(5000);
    digitalWrite(motorPin, LOW);  // Turn the motor of
    Serial.print("End Watering");
  }
  delay(1000);  // Delay a bit to make it more readable
}