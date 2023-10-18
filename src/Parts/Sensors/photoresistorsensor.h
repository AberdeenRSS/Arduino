#pragma once

#include "Parts/AParts/asensor.h"

class PhotoResistorSensor : public ASensor<PhotoResistorSensor> {
public:
    PhotoResistorSensor();

    virtual void update()    override;
    virtual char read_data() override;
};