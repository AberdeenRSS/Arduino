#include "commandmessage.h"
#include "errors.h"

char CommandMessage::getPart() const  {
    return message[3];
}

char CommandMessage::getCommand() const  {
    return message[4];
}

char CommandMessage::check() const  {
    for(int i = 0; i < 6; ++i) {
        switch(i){
        case (StartByte) :  {
            if (message[i] != MessageSE)          
                return Errors::WrongStartByte; 
            break;
        }
        case (ConnectionsByte) : {
            if (message[i] != AndroidArduino)            
                return Errors::WrongConnectionByte; 
            break;
        }
        case (StateByte) : { 
            if (message[i] != Command)    
                return Errors::WrongStateByte; 
            break;
        }

        case (EndByte) : { 
            if (message[i] != MessageSE)          
                return Errors::WrongEndByte; 
            break;
        }

        case (ComponentByte)    : break;
        
        case (CommandByte)      : break;
                
        default                 : break;
        }
    }

    return Errors::Success;
}