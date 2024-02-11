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

  myArduino->registerPart(make_Sensor<MArduno>());
  myArduino->registerPart(make_Sensor<MyServo>());
  myArduino->registerPart(make_Sensor<Igniter>());

  // myArduino->registerSensor(make_Sensor<PressureSensor>());
  myArduino->registerSensor(make_Sensor<OrientationSensor>());

  OurSerial::startSerial();
}

void loop() { 
  OurSerial::receive(); 
  myArduino->update(); 
  myArduino->read_data();
}

