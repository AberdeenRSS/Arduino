#include "temperaturesensor.h"

#include <Arduino.h>

AnalogThemp::AnalogThemp() 
            :   ASensor(0x50, 4),  
                dht(2, DHT11) {     
    dht.begin();

    addCommand(this,  0x00, [](AnalogThemp* t) { return t->read_data(); });
}

char AnalogThemp::read_data() {
    float data = dht.readTemperature();
    return send_Message(data);
}

void AnalogThemp::update()   {

}




