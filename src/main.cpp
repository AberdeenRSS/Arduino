#include <Arduino.h>

#include "Serial/hdlc_serial.h"
#include "myarduino.h"

#include "type_utils.h"

#include "Parts/Parts/myservo.h"
#include "Parts/Parts/igniter.h"
#include "Parts/Parts/marduino.h"
#include "Parts/Sensors/photoresistorsensor.h"
#include "Parts/Sensors/pressuresensor.h"
#include "Parts/Sensors/orientationsensor.h"

MyArduino* myArduino = getSingleton<MyArduino>();

void setup() {
  Serial.begin(9600);

  myArduino->registerPart(getSingleton<MArduno>());
  myArduino->registerPart(getSingleton<MyServo>());
  myArduino->registerPart(getSingleton<Igniter>());

  myArduino->registerSensor(getSingleton<PressureSensor>());
  myArduino->registerSensor(getSingleton<OrientationSensor>());

  HdlcSerial::startSerial();
}

void loop() { 
  HdlcSerial::receive(); 
  myArduino->update(); 
  myArduino->read_data();
}

