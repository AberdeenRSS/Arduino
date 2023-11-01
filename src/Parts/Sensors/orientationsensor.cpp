#include "orientationsensor.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>


OrientationSensor::OrientationSensor() 
    : ASensor(0x54),
      bno(Adafruit_BNO055(55)) {

    //addCommand(this,  0x00, [](PressureSensor* t) { return t->read_data(); }, LaunchPhase::Init);

    addCommand(this,  0x00, [](OrientationSensor* t) { return t->read_data(); });
    
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
   
  }

  bno.setExtCrystalUse(true);
}


void OrientationSensor::update() {
    
}

char OrientationSensor::read_data() {
  /* Get a new sensor event */
    sensors_event_t event;
    bno.getEvent(&event);


    send_Message(event.orientation.x);
    send_Message(event.orientation.y, 0x02);
    return send_Message(event.orientation.z, 0x03);
}