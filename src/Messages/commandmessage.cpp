#include "commandmessage.h"
#include "errors.h"

CommandMessage::CommandMessage() {
    arr[0] = 0; 
    arr[1] = 0;
    arr[2] = 0;

    arr[0] |= 1 << 7;  
}


char CommandMessage::getPart() const {
    unsigned char mask = 63; 
        
    return arr[0] & mask;
}
    
char CommandMessage::getCommand() const {
    unsigned char mask = 15; 
    return (arr[2] >> 4) & mask;
}
    
int CommandMessage::getIndex() const {
    return arr[0];
}
       
void CommandMessage::sendResponse(char result) {
    arr[0] |= 1 << 6;
    arr[2] |= result;

    OurSerial::sendPacket(reinterpret_cast<char*>(arr), 3); 
}

void CommandMessage::send()  {
    OurSerial::sendPacket(reinterpret_cast<char*>(arr), 3); 
}