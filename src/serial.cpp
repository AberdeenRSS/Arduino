#include <serial.hpp>
#include <TinyProtocol.h>


u8* buffer[128];

tinyproto::Hdlc hdlc(buffer, 128);

tinyproto::StaticPacket<64> tinyPacket;

RSSPacket rssPacket;

u8 message_index;

void (*on_receive)(RSSPacket &pkt) = nullptr;

int write(void *pdata, const void *buffer, int size){
    return Serial.write((char*)buffer, size);
}

int read(void *pdata, void *buffer, int size){
    return Serial.readBytes((char*)buffer, size);
}

void onReceive(tinyproto::IPacket &pkt){

    rssPacket.index = pkt.getByte();
    rssPacket.command = pkt.getByte();
    rssPacket.payloadLength = pkt.getByte();

    for(u8 i = 0; i < rssPacket.payloadLength; i++)
        tinyPacket.put(rssPacket.payload[i]);

    on_receive(rssPacket);
}

void startHardwareSerial(void (*on_receive_callback)(RSSPacket &pkt)){

    on_receive = on_receive_callback;

    Serial.begin(9600);

    hdlc.enableCheckSum();

    hdlc.setReceiveCallback(onReceive);

    hdlc.begin();
    
}


char* read_write_buffer[64];

void runRead(){

    
    if(Serial.available() < 1){
        return;
    }

    size_t readBytes = Serial.readBytes((char*)read_write_buffer, 64);


    hdlc.run_rx(read_write_buffer, readBytes);
}

void write(RSSPacket &packet){

    packet.index = message_index++;

    tinyPacket.clear();
    tinyPacket.put(packet.index);
    tinyPacket.put(packet.command);
    tinyPacket.put(packet.payloadLength);

    for(u8 i = 0; i < packet.payloadLength; i++)
        tinyPacket.put(packet.payload[i]);

    hdlc.write(tinyPacket);

    size_t toSend = hdlc.run_tx(read_write_buffer, 64);

    Serial.write((char*) read_write_buffer, toSend);
}

