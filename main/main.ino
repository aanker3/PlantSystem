#include "sensor.h"
#include "plant.h"
#include "helpers.h"

const int motorPin = 13; // Adjust this pin according to your setup
Plant fern;
Sensor moisture(A0);

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);

  //Setup Plants
  fern.setMoistureValue(2.0);
}

  void loop() {
  moisture.getMeasuredValue();
  float moisture_value = moisture.getMeasuredValue();

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println("Moisture_Sensor_A0: " + String(moisture_value));
  Serial.println("TimeElapsed= " + String(GetTimeElapsedMilliseconds()) + " MilliSeconds");
  Serial.println("TimeElapsed= " + String(GetTimeElapsedSeconds()) + " Seconds");
  
Serial.println("TimeElapsed= " + String(GetTimeElapsedMinutes()) + " Minutes");
  if(moisture_value < fern.getDesiredMoistureValue())
  {
    Serial.println("WATERING!!! SENSOR_VALUE = " + String(moisture_value));

    digitalWrite(motorPin, HIGH); // Turn the motor on
    delay(5000);
    digitalWrite(motorPin, LOW);  // Turn the motor of
    fern.plantWatered();
    Serial.println("End Watering.  Times Watered = " + String(fern.getTimesWatered()));
  }
  delay(1000);  // Delay a bit to make it more readable
}


//   void loop() {
//   float sensor_valueA0 = SensorValueInVoltage(analogRead(A0));

//   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//   Serial.print("Moisture_Sensor_A0: " + String(sensor_valueA0));

//   if(sensor_valueA0 < fern.getMoistureValue())
//   {
//     Serial.print("WATERING!!! SENSOR_VALUE = " + String(sensor_valueA0));

//     digitalWrite(motorPin, HIGH); // Turn the motor on
//     delay(5000);
//     digitalWrite(motorPin, LOW);  // Turn the motor of
//     Serial.print("End Watering");
//   }
//   delay(1000);  // Delay a bit to make it more readable
// }