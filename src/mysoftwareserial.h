#pragma once

#include <SoftwareSerial.h>

class AbstractSensor: public SoftwareSerial {

public:
  AbstractSensor(int rxPins, int txPins) 
  : SoftwareSerial(rxPins, txPins) {}

  virtual void message() const;
  virtual void loop()  = 0;
};