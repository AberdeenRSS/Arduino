#pragma once

#include "mysoftwareserial.h"
#include <DHT.h>
#include <DHT_U.h>



class HumTemp : public AbstractSensor {

public:

  HumTemp();

  void init();

  virtual void message() const override;

  virtual void loop()  override;

};
