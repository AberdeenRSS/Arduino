#pragma once

#include <TinyProtocol.h>

class Message {
  enum MessageBound  { MessageSE = 0x7E };
  enum Connections   { AndroidArduinoConnection = 0xFF, ArduinoAndroidConnection = 0xFE };
  enum State         { MessageReceived = 0x4F, MessageSent = 0x4E };
  enum Result        { Success = 0x01, Error = 0x02 };
  enum MessageStruct { StartByte = 1, ConnectionsByte, StateByte, ComponentByte, CommandByte, EndByte };

public:
  enum Commands      { CloseServo = 0x03, OpenServo = 0x04 };
  enum Component     { Reset = 0x00, Servo = 0x01, Igniter = 0x02 };

public:
  Message(tinyproto::IPacket &pkt);

  char  get_command() const;
  char  get_part()    const;
  void  set_result_byte(char result);
  char* get_response();

private:
  Connections connection;
  State       state;
  char        component;
  char        command;
  char        response[7];

private:
  int  messageBounds(char c) const;
  void setState(unsigned char c);
  void connectionBytes(char c); 
  void parse(tinyproto::IPacket &pkt);
};