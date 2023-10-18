#pragma once

#include <SoftwareSerial.h>
#include <DHT.h>
#include "Parts/AParts/asensor.h"


class AnalogThemp : public ASensor<AnalogThemp> {
public:

    AnalogThemp();

    virtual void update()    override;
    virtual char read_data() override;

private:
    DHT dht;
};