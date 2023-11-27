#include "ourserial.h"
#include "myarduino.h"
#include "Parts/AParts/apart.h"
#include "Messages/commandmessage.h"
#include "Messages/sensormessage.h"
#include "errors.h"

namespace OurSerial {
    MyArduino* myArduino = make_Sensor<MyArduino>();

    char buf[128];
    tinyproto::Light proto;
    tinyproto::Hdlc hdlc(static_cast<void*>(buf), 128); 


    void onReceive(tinyproto::IPacket &pkt) {
        void* data = pkt.data();
        CommandMessage* msg1 = static_cast<CommandMessage*>(data);

        char result = myArduino->find(msg1->getPart(), msg1->getCommand());
        msg1->sendResponse(result);
    }

    void startSerial() {
        hdlc.setReceiveCallback(onReceive);
        hdlc.enableCheckSum();
        hdlc.begin();

        bool hzz = proto.enableCheckSum();
        proto.beginToSerial();
    }

    void receive() {
        if (Serial.available()) {
            uint8_t byte = Serial.read();
            hdlc.run_rx( &byte, 1 ); 
        }
    }

    void sendPacket(char* data_buffer, int numberBytes){
        proto.write(data_buffer, numberBytes);
    }
}