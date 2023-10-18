#pragma once

#include "Parts/AParts/asensor.h"

class SensorName : public ASensor<SensorName> {
public:
    SensorName();

    virtual void update()    override;
    virtual char read_data() override;

private:

};