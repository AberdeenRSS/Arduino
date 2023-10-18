#pragma once
#include <TinyProtocol.h>

namespace OurSerial {
    void startSerial();

    void receive();

    void sendPacket(unsigned char* data_buffer, int n = 7);
}