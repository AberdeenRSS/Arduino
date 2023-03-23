#pragma once

#include "mysoftwareserial.h"

class AnalogThemp : public AbstractSensor {

public:

  AnalogThemp();

  void init();

  virtual void message() const override;

  virtual void loop()  override;

};
