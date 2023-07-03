#include "ourserial.h"

namespace OurSerial {
    char buffer[128];

    tinyproto::Hdlc hdlc1(buffer, 128);

    tinyproto::StaticPacket<64> tinyPacket;

    char data_buffer[128];

     void startSerial(void (*on_receive_callback)(tinyproto::IPacket &pkt)) {
        // Serial.begin(9600);

        hdlc1.enableCheckSum();

        hdlc1.setReceiveCallback(on_receive_callback);

        hdlc1.begin();

    }

    void receive() {
        while(Serial.available()) {
            uint8_t byte = Serial.read();
            hdlc1.run_rx( &byte, 1 ); // run FD protocol parser to process data received from the channel
        } 
    }

    void sendPacket(){
        tinyPacket.clear();
        

        hdlc1.write(tinyPacket);

        hdlc1.run_tx(data_buffer, 128);
        hdlc1.run_rx(data_buffer, 128);
    }

    void sendPacket(char* data_buffer){
        Serial.write(data_buffer, 7);
    }
}