#include "photoresistorsensor.h"
#include <Arduino.h>

PhotoResistorSensor::PhotoResistorSensor() : ASensor(0x52, 2) {
    pinMode(A2, INPUT);

    addCommand(this,  0x00, [](PhotoResistorSensor* t) { return t->read_data(); });
}

char PhotoResistorSensor::read_data() {
    float data = analogRead(2); 
	//Serial.println(value, DEC); // light intensity

   // return send_Message(data);
}

void PhotoResistorSensor::update()   {

}


