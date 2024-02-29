#include "hw_peripheral_factory.h"

HwPeripheralBase* HwPeripheralFactory::createHwPeripheral(const std::string& hwName, uint8_t hwPin)
{
  if (hwName == "MoistureSensor")
    return new MoistureSensor(hwPin);
  else if (hwName == "Motor")
    return new Motor(hwPin);
  else
    return nullptr; // Return nullptr or throw an exception for unknown hardware names
}