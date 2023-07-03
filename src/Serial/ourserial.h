#pragma once
#include <TinyProtocol.h>
// #include <tinyproto/TinyProtocolhdlc1.h>


namespace OurSerial {
    void startSerial(void (*on_receive_callback)(tinyproto::IPacket &pkt));

    void receive();

    void sendPacket();

    void sendPacket(char* data_buffer);
}