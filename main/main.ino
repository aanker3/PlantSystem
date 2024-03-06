#include "src/objects/hw_peripherals/moisture_sensor.h"
#include "src/objects/plants/plant.h"
#include "src/objects/plants/plant_factory.h"
#include "src/objects/watering_manager.h"
#include "src/helpers/timing.h"
#include "src/objects/hw_peripherals/motor.h"
#include <vector>

#define START_OF_TIMER 0

WateringManager* wateringManager = NULL;

// Global Variables
unsigned long previousTime = 0; // Stores the last time we updated the day count
uint16_t daysElapsed = 0; // Stores the number of days elapsed
uint16_t weeksElapsed = 0;

void setup() {
  Serial.begin(9600);

  wateringManager = new WateringManager();
  wateringManager->addPlantSystem("fern", PotSize::Medium, A0, 13);
  wateringManager->addPlantSystem("cactus", PotSize::Medium, A1, 12);
  //wateringManager->addPlantSystem("basil", A2, 11);

}

void loop() {

  // Call GetTimeAndUpdate regularly to update time and count days
  getTimeAndUpdate(previousTime, daysElapsed);

  // Check if two weeks have elapsed.
  if (twoWeeksElapsed(daysElapsed)) {
    weeksElapsed++;
    //Reset watering period
    wateringManager->printTwoWeekResults(weeksElapsed);
    wateringManager->resetPlants();
  }
  else
  {
    Serial.println("days elapsed = " + String(daysElapsed));
  }

  Serial.println("test");
  //wateringManager->printPlantSystemsInfo();
  wateringManager->gatherSensorData();
  wateringManager->waterPlantsIfNeeded();

  delay(1000);
}


//   void loop() {
//   Serial.println("Cactus Moisture Value = " + String(cactus->getMoistureWateringPoint()));
//   moisture.getMeasuredValue();
//   float moisture_value = moisture.getMeasuredValue();

//   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//   Serial.println("Moisture_Sensor_A0: " + String(moisture_value));

//   GetTimeAndUpdate(previousTime, daysElapsed);
//   Serial.println("daysElapsed = " + String(daysElapsed));



//   Serial.println("TimeElapsed= " + String(GetTimeElapsedMinutes()) + " Minutes");
  
//   if(moisture_value < fern->getMoistureWateringPoint())
//   {
//     Serial.println("WATERING!!! SENSOR_VALUE = " + String(moisture_value));
//     fernMotor.motor5s();
//     fern->plantWatered();
//     Serial.println("End Watering.  Times Watered = " + String(fern->getTimesWatered()));
//   }
//   delay(1000);  // Delay a bit to make it more readable
// }


//   void loop() {
//   float sensor_valueA0 = SensorValueInVoltage(analogRead(A0));

//   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//   Serial.print("Moisture_Sensor_A0: " + String(sensor_valueA0));

//   if(sensor_valueA0 < fern.getCurrentMoistureValue())
//   {
//     Serial.print("WATERING!!! SENSOR_VALUE = " + String(sensor_valueA0));

//     digitalWrite(motorPin, HIGH); // Turn the motor on
//     delay(5000);
//     digitalWrite(motorPin, LOW);  // Turn the motor of
//     Serial.print("End Watering");
//   }
//   delay(1000);  // Delay a bit to make it more readable
// }