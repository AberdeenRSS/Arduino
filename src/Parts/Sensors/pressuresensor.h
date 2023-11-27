#pragma once

#include "Parts/AParts/asensor.h"
#include "Adafruit_BMP3XX.h"

class PressureSensor : public ASensor<PressureSensor> {
public:
    PressureSensor();

    virtual void update()    override;
    virtual char read_data() override;

private:
    Adafruit_BMP3XX bmp;
};