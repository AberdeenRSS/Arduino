#pragma once

#include "amessage.h"

class SensorMessage : public AMessage {
public:
   static char sendMessage(char, float);
};

struct CommandResponseMessage : AMessage {
   static char sendMessage(char partCode, char commandCode, char result);
};

struct LaunchPhaseMessage : AMessage {
   static char sendMessage(char partCode = 0x00);
};

