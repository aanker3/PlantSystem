#include "src/objects/hw_peripherals/moisture_sensor.h"
#include "src/objects/plants/plant.h"
#include "src/objects/plants/plant_factory.h"
#include "src/objects/watering_manager.h"
#include "src/helpers/timing.h"
#include "src/objects/hw_peripherals/motor.h"
#include "src/objects/hw_peripherals/ultrasonic_sensor.h"
#include <vector>

WateringManager* wateringManager = NULL;
UltrasonicSensor* ultrasonicSensor = NULL;

// Global Variables
unsigned long previousTime = 0; // Stores the last time we updated
uint16_t daysElapsed = 0; // Stores the number of days elapsed
uint16_t weeksElapsed = 0;

void setup() {
  Serial.begin(9600);

  ultrasonicSensor = new UltrasonicSensor(3,4);
  wateringManager = new WateringManager();
  //Plant Name, PotSize, MoistureSensorPin, MotorPin
  wateringManager->addPlantSystem("fern", PotSize::Medium, A0, 13);
  wateringManager->addPlantSystem("cactus", PotSize::Medium, A1, 12);
  //wateringManager->addPlantSystem("basil", A2, 11);

}

void loop() {

  // Call getTimeAndUpdateDaysElapsed to update time and count days
  getTimeAndUpdateDaysElapsed(previousTime, daysElapsed);

  // Check if a week has elapsed.
  if (weekElapsed(daysElapsed)) {
    weeksElapsed++;
    //Reset watering period
    wateringManager->printWeeklyResults(weeksElapsed);
    wateringManager->resetPlants();
  }
  else
  {
    Serial.println("days elapsed = " + String(daysElapsed));
  }

  //wateringManager->printPlantSystemsInfo();
  wateringManager->gatherSensorData();
  wateringManager->waterPlantsIfNeeded();

  Serial.println("ultrasonic reading = " + String(ultrasonicSensor->getMeasuredValue()));

  delay(1000);
}
