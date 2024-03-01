#pragma once

#include "errors.h"
#include "Serial/hdlc_serial.h"


class CommandMessage{
public:
    CommandMessage();
    
    char getPart()    const;
    char getCommand() const;
    int  getIndex()   const;
    void sendResponse(char result);
    void send();
    
private:
    char arr[6];
};