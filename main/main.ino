#include "src/objects/hw_peripherals/moisture_sensor.h"
#include "src/objects/plants/plant.h"
#include "src/objects/plants/plant_factory.h"
#include "src/objects/watering_manager.h"
#include "helpers.h"
#include "src/objects/hw_peripherals/motor.h"
#include <vector>

#define START_OF_TIMER 0

WateringManager* wateringManager = NULL;

void setup() {
  Serial.begin(9600);

  wateringManager = new WateringManager();
  wateringManager->addPlantSystem("fern", A0, 13);
  wateringManager->addPlantSystem("cactus", A1, 12);
  //wateringManager->addPlantSystem("basil", A2, 11);

  //pinMode(motorPin, OUTPUT);

}

void loop() {

  Serial.println("test");
    

    // for (Plant* plant : plantVector) {
    //     if (plant != nullptr) {
    //         Serial.println("plant Name = " + String(plant->getName().c_str()));
    //         Serial.println("plant Moisture Value = " + String(plant->getMoistureWateringPoint()));

    //         // Example function call, assuming Plant has a method named 'displayInfo'
    //         // plant->displayInfo();
    //     }
    // }
    //Serial.println("fern plant Name = " + String(fern->getName().c_str()));
    wateringManager->printPlantSystemsInfo();
    wateringManager->gatherSensorData();
    wateringManager->waterPlantsIfNeeded();
  
  //Serial.println("Cactus Moisture Value = " + String(cactus->getMoistureWateringPoint()));
  //Serial.println("Fern Moisture Value = " + String(fern->getMoistureWateringPoint()));

  delay(1000);  // Delay a bit to make it more readable
}


//   void loop() {
//   Serial.println("Cactus Moisture Value = " + String(cactus->getMoistureWateringPoint()));
//   moisture.getMeasuredValue();
//   float moisture_value = moisture.getMeasuredValue();

//   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//   Serial.println("Moisture_Sensor_A0: " + String(moisture_value));

//   GetTimeAndUpdate(previousTime, days_elapsed);
//   Serial.println("days_elapsed = " + String(days_elapsed));



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