#include <Arduino.h>

#include <TinyProtocol.h>
#include <Adafruit_Sensor.h>

#include "Serial/ourserial.h"
#include "myarduino.h"

#include "Parts/Parts/myservo.h"
#include "Parts/Parts/igniter.h"
#include "Parts/Sensors/temperaturesensor.h"
#include "Parts/Parts/marduino.h"
#include "Parts/Sensors/photoresistorsensor.h"


MyArduino* myArduino = make_Sensor<MyArduino>();


 
void setup() {
  Serial.begin(9600);

  myArduino->reg(make_Sensor<MArduno>());
  myArduino->reg(make_Sensor<MyServo>());
  myArduino->reg(make_Sensor<Igniter>());
  myArduino->reg(make_Sensor<AnalogThemp>());
  myArduino->reg(make_Sensor<PhotoResistorSensor>());

  OurSerial::startSerial();

 // myArduino->show();
}

void loop() {
  OurSerial::receive();  
  myArduino->update();
 // myArduino->read_data();
}

/*

  int i = Serial.read();
  if (i == 48) {
    unsigned char close[] = {0x7E, 0xFF, 0x4F, 0x01,  0x00, 0x7E};
   // void* data = close;
  //  MSG* message = static_cast<MSG*>(data);
    myArduino->find(close[3], close[4]);

  }
  else if(i == 49) {
    unsigned char open[] = {0x7E, 0xFF, 0x4F, 0x01, 0x01, 0x7E};
    myArduino->find(open[3], open[4]);
  }

  else if(i == 50) {
    unsigned  char open[] = {0x7E, 0xFF, 0x4F, 0x02, 0x00, 0x7E};
    myArduino->find(open[3], open[4]);

  }
  else if(i == 51) {
    unsigned  char open[] = {0x7E, 0xFF, 0x4F, 0x00, 0x00, 0x7E};
    myArduino->find(open[3], open[4]);
  }
  else if(i == 52) {
    unsigned  char open[] = {0x7E, 0xFF, 0x4F, 0x00, 0x01, 0x7E};
    myArduino->find(open[3], open[4]);
  }

}



void setup() {
  Serial.begin(9600);
  int* s;
  int i = sizeof(s);
  Serial.println(i);
}
void loop() {


}

*/