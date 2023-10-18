#include "ourserial.h"
#include "myarduino.h"
#include "Parts/AParts/apart.h"
#include "Messages/commandmessage.h"
#include "Messages/sensormessage.h"
#include "errors.h"

namespace OurSerial {
    MyArduino* myArduino = make_Sensor<MyArduino>();

   // char ourBuffer[128];

   // tinyproto::Hdlc hdlc1(ourBuffer, 128);
    tinyproto::Light  proto;
    tinyproto::StaticPacket<64> tinyPacket;

   // char data_buffer[128];

    void onReceive(void* data) {
        CommandMessage* msg1 = static_cast<CommandMessage*>(data);
        char result = msg1->check();

        if (result == Errors::Success)
            result = myArduino->find(msg1->getPart(), msg1->getCommand());
        

        CommandResponseMessage::sendMessage(msg1->getPart(), msg1->getCommand(), result);
    }

     void startSerial() {
       //Serial.begin(9600);

       proto.beginToSerial();
    }


    void receive() {
        if(Serial.available()) {
            int hz = proto.read(tinyPacket);
             if (hz > 0)
                onReceive(tinyPacket.getString());

        }
    }

/*
    void sendPacket(){
      //  tinyPacket.clear();

    //    hdlc1.write(tinyPacket);

    //    hdlc1.run_tx(data_buffer, 128);
     //   hdlc1.run_rx(data_buffer, 128);
    }
*/

    void sendPacket(unsigned char* data_buffer, int numberBytes){
        Serial.write(data_buffer, numberBytes);
    }
}