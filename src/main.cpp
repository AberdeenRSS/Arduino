#include <Arduino.h>

#include "temph.h"
#include "mysoftwareserial.h"
#include "tempanalog.h"
#include "myservo.h"

#include <serial.hpp>

MyServo myServo;
AnalogThemp analogTempSensor;
HumTemp humTempSensor;
AbstractSensor* arr[2];




// void setup() {
//   Serial.begin(9600);
//   myServo.init();

//   arr[0] = &analogTempSensor;
//   arr[1] = &humTempSensor;

//   analogTempSensor.init();
//   humTempSensor.init();

//   analogTempSensor.listen();
// }

// char message;

// void input() {
//   while(Serial.available()) {
//       char c = Serial.read();

//         if (c == 48 || c == 49)
//           message = c;
//         else if (c == 13) {
//           if (message == 48) {
//             myServo.open();
//             Serial.write("OPEN!!!\n");
//           }
//           else if (message == 49){
//             myServo.close();
//             Serial.write("CLOSE!!!\n");
//           }
//           message = 50;
//         }
//   }
// }

// void loop() {
//   for  (auto sensor : arr) {
//     sensor->listen();
//     sensor->loop();
//     input();
//     delay(1000);
//   }
// }

void onPacket(RSSPacket &packet){

}

void setup(){

  Serial.begin(9600);


  startHardwareSerial(onPacket);

}

void loop(){

  runRead();

  RSSPacket packet;

  packet.command = 0x22;
  packet.payloadLength = 0;

  delay(1000);

  write(packet);
}
