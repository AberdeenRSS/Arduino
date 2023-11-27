#pragma once

#include "Serial/ourserial.h"

class SensorMessages {
public:
    SensorMessages(char partID, char type, char payloadL = 1);
    
    void addData(short data);
    int getPart() const;
    void sendMessage();
    
private:
    char arr[8];
    uint8_t i;
};