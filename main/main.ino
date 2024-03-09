#include "src/objects/hw_peripherals/moisture_sensor.h"
#include "src/objects/plants/plant.h"
#include "src/objects/plants/plant_factory.h"
#include "src/objects/watering_manager.h"
#include "src/helpers/timing.h"
#include "src/objects/hw_peripherals/motor.h"
#include <vector>

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

  // Call GetTimeAndUpdate to update time and count days
  getTimeAndUpdate(previousTime, daysElapsed);

  // Check if two weeks have elapsed.
  if (twoWeeksElapsed(daysElapsed)) {
    weeksElapsed = weeksElapsed + 2;
    //Reset watering period
    wateringManager->printTwoWeekResults(weeksElapsed);
    wateringManager->resetPlants();
  }
  else
  {
    Serial.println("days elapsed = " + String(daysElapsed));
  }

  //wateringManager->printPlantSystemsInfo();
  wateringManager->gatherSensorData();
  wateringManager->waterPlantsIfNeeded();

  delay(1000);
}
