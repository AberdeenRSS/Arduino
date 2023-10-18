#pragma once

#include "amessage.h"
#include "errors.h"

class CommandMessage : public AMessage {
public:
    char check() const;
    char getPart() const;
    char getCommand() const;

private:
    unsigned char message[6];
};