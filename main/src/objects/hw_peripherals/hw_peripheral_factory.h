#ifndef HW_PERIPHERAL_FACTORY_H
#define HW_PERIPHERAL_FACTORY_H

#include "hw_peripheral_base.h"
#include <string>
#include "Arduino.h"
#include "moisture_sensor.h"
#include "motor.h"

class HwPeripheralFactory {       // The class
  public:             // Access specifier
    static HwPeripheralBase* createHwPeripheral(const std::string& hwName, uint8_t hwPin);
};


#endif