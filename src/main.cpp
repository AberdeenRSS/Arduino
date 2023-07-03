#include <Arduino.h>
#include <TinyProtocol.h>

#include "Serial/ourserial.h"
#include "myarduino.h"
#include "message.h"

MyArduino myArduino;


void onReceive(tinyproto::IPacket &pkt) {
  Message message(pkt);
  char result = myArduino.action(message.get_part(), message.get_command());
  message.set_result_byte(result);
  OurSerial::sendPacket(message.get_response());
}


void setup() {
  Serial.begin(9600);
  myArduino.init();
  OurSerial::startSerial(onReceive);
}

void loop() {
  OurSerial::receive();  
  myArduino.update();
}
