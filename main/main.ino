#include "src/objects/sensors/moisture_sensor.h"
#include "src/objects/plants/fern_plant.h"
#include "helpers.h"
#include "motor.h"

#define START_OF_TIMER 0

const int motorPin = 13; // Adjust this pin according to your setup
FernPlant fern;
MoistureSensor moisture(A0);
Motor fernMotor(13);

void setup() {
  Serial.begin(9600);
  //pinMode(motorPin, OUTPUT);

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

  // todo redo this.  this wont work.  In order for this to work, we need to get lucky and hit exactly 0.
  if (GetTimeElapsedMilliseconds == START_OF_TIMER)
  {
    fern.reset();
  }

Serial.println("TimeElapsed= " + String(GetTimeElapsedMinutes()) + " Minutes");
  if(moisture_value < fern.getDesiredMoistureValue())
  {
    Serial.println("WATERING!!! SENSOR_VALUE = " + String(moisture_value));
    fernMotor.motor5s();
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