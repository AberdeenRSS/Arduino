#include "sensormessage.h"
#include <Arduino.h>
#include "Serial/ourserial.h"
#include "errors.h"

char SensorMessage::sendMessage(char partCode, float data) {
    char messageBuffers[40];
    char floatStr[20]; 

    dtostrf(data, 1, 2, floatStr);  
    int val = snprintf(messageBuffers + 5,  sizeof(messageBuffers), "%s", floatStr);

    messageBuffers[0] = messageBuffers[5 + val] = MessageBound::MessageSE;
    messageBuffers[1] = Connections::ArduinoAndroid;
    messageBuffers[2] = MessageType::Sensor;
    messageBuffers[3] = partCode;
    messageBuffers[4] = (char)val;

    OurSerial::sendPacket(static_cast<unsigned char*>(static_cast<void*>(messageBuffers)), val + 6);

    return Errors::Success;
}


char CommandResponseMessage::sendMessage(char partCode, char commandCode, char result) {
    unsigned char messageBuffers[7];

    messageBuffers[0] = messageBuffers[6] = MessageBound::MessageSE;
    messageBuffers[1] = Connections::ArduinoAndroid;
    messageBuffers[2] = MessageType::Command;
    messageBuffers[3] = partCode;
    messageBuffers[4] = commandCode;
    messageBuffers[5] = result;

    OurSerial::sendPacket(messageBuffers);

    return Errors::Success;
}


char LaunchPhaseMessage::sendMessage(char partCode) {
    unsigned char messageBuffers[5];

    messageBuffers[0] = messageBuffers[4] =  MessageBound::MessageSE;
    messageBuffers[1] = Connections::ArduinoAndroid;
    messageBuffers[2] = MessageType::Phase;
    messageBuffers[3] = partCode;

    OurSerial::sendPacket(messageBuffers, 5);

    return Errors::Success;
}






