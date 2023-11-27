#include "sensormessage.h"
#include <Arduino.h>
#include "Serial/ourserial.h"
#include "errors.h"


SensorMessages::SensorMessages(char partID, char type, char payloadL)
    : i(1) {

    for (uint8_t j = 0; j < 8; ++j)
        arr[j] = 0;

    arr[0] = partID;
    arr[1] |= type << 4;
    arr[1] |= payloadL;
}

void SensorMessages::addData(short data) {
    short* ptr = reinterpret_cast<short*>(arr + i * 2);
    *ptr = data;
    ++i;
}

int SensorMessages::getPart() const {
    unsigned char mask = 127; 
        
    return arr[0] & mask;
}

void SensorMessages::sendMessage() {
    OurSerial::sendPacket(reinterpret_cast<char*>(arr), 2 + (i - 1) * 2);
}