#include "templateSensor.h"

SensorName::SensorName() : ASensor(0x90) {

    addCommand(this,  0x00, [](SensorName* t) { return t->read_data(); });
}


void SensorName::update() {
    
}

char SensorName::read_data() {
    return Errors::Success;
}