#pragma once
#include <TinyProtocol.h>

namespace HdlcSerial {
    void startSerial();

    void receive();

    void sendPacket(char* data_buffer, int n = 7);
}