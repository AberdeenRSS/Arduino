#include <Arduino.h>

#include "Serial/ourserial.h"
#include "myarduino.h"

#include "Parts/Parts/myservo.h"
#include "Parts/Parts/igniter.h"
#include "Parts/Parts/marduino.h"
#include "Parts/Sensors/photoresistorsensor.h"
#include "Parts/Sensors/pressuresensor.h"
#include "Parts/Sensors/orientationsensor.h"

MyArduino* myArduino = make_Sensor<MyArduino>();

void setup() {
  Serial.begin(9600);

  myArduino->reg(make_Sensor<MArduno>());
  myArduino->reg(make_Sensor<MyServo>());
  myArduino->reg(make_Sensor<Igniter>());
  myArduino->reg(make_Sensor<PressureSensor>());
  myArduino->reg(make_Sensor<OrientationSensor>());

  OurSerial::startSerial();

  //myArduino->show();
}

void loop() { 
  OurSerial::receive(); 
  myArduino->update(); 
  myArduino->read_data();
}

