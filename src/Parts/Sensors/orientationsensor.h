#pragma once

#include "Parts/AParts/asensor.h"
#include <Adafruit_BNO055.h>

class OrientationSensor : public ASensor<OrientationSensor> {
public:
    OrientationSensor();

    virtual void update()    override;
    virtual char read_data() override;

private:
    Adafruit_BNO055 bno;
};