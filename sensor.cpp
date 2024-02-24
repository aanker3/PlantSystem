#include "sensor.h"

Sensor::Sensor(uint8_t dio) : dio_value(dio){
  setSensorDio(dio);
}

Sensor::~Sensor(){

}

void Sensor::setSensorDio(uint8_t value){
  dio_value = value;
}
uint8_t Sensor::getSensorDio() {
  return dio_value;
}