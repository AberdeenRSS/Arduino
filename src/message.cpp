#include "message.h"

Message::Message(tinyproto::IPacket &pkt)
      : connection(AndroidArduinoConnection),
        state(MessageReceived),
        command(CloseServo) {

    parse(pkt);

    response[0] = response[6] = MessageSE;
    response[1] = ArduinoAndroidConnection;
    response[2] = MessageSent;
    response[3] = component;
    response[4] = command;
}

char Message::get_command() const {
    return command;
}


char  Message::get_part() const {
    return component;
}

void  Message::set_result_byte(char result) {
    response[5] = result;
}

char*  Message::get_response() {
    return response;
}

int  Message::messageBounds(char c) const {
      return c == MessageSE;
}

void  Message::setState(unsigned char c) {

    switch (c)
    {
    case (AndroidArduinoConnection):
      connection = AndroidArduinoConnection;
      break;

    case (ArduinoAndroidConnection):
      connection = ArduinoAndroidConnection;
      break;
    
    default:
      break;
    }
}

void  Message::connectionBytes(char c) {
    switch (c)
    {
    case (MessageReceived):
      state = MessageReceived;
      break;

    case (MessageSent):
      state = MessageSent ;
      break;
    
    default:
      break;
    }
}

void Message::parse(tinyproto::IPacket &pkt) {
    int messageLength = 1;

    char c = pkt.getChar();

    while (messageLength != 6)
    {
      switch (messageLength)
      {
      case (StartByte):
        break;

      case (EndByte):
        if(messageBounds(c))
          return;
        break;

      case (ConnectionsByte):
        connectionBytes(c);
        break;

      case (StateByte):
        setState(c);
        break;        

      case (ComponentByte):
        component = c;
        break;

      case (CommandByte):
        command = c;
        break;           

      default:
        break;
      }

    messageLength++;
    c = pkt.getChar();
    }

}