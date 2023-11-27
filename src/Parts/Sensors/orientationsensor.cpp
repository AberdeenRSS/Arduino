#include "orientationsensor.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>


OrientationSensor::OrientationSensor() 
    : ASensor(0x54),
      bno(Adafruit_BNO055(55)) {

    addCommand(this,  0x00, [](OrientationSensor* t) { return t->read_data(); });
    
  if(!bno.begin())
  {
   
  }

  bno.setExtCrystalUse(true);
}


void OrientationSensor::update() {
    
}

char OrientationSensor::read_data() {
    sensors_event_t event;
    bno.getEvent(&event);

    send_Message(event.orientation.x, event.orientation.y, event.orientation.z);
    return 0;
}