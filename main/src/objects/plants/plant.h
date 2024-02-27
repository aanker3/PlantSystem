#ifndef PLANT_H
#define PLANT_H

//Abstracted Based Plant class
class Plant {
  public:
    Plant(float desiredMoisture);
    ~Plant();

    void setMoistureValue(float value); // Setter for moistureValue
    float getMoistureValue() const; // Getter for moistureValue

    float getDesiredMoistureValue() const; // Getter for desiredMoistureValue

    void plantWatered(); // Setter for timesWatered
    int getTimesWatered() const; // Getter for timesWatered
    
    void reset(); //Reset Variables (usually after 50 Day Timeout)
  protected:
    int moistureValue;
    int timesWatered;  // Amount of times plant has been watered
    float desiredMoistureValue;

};

#endif