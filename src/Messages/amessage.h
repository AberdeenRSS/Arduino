#pragma once

class AMessage {
protected:
    enum MessageStruct { StartByte = 0, ConnectionsByte = 1, StateByte, ComponentByte, CommandByte, EndByte };
    enum MessageBound  { MessageSE = 0x7E };
    enum Connections   { AndroidArduino = 0x00, ArduinoAndroid = 0x01 };
    enum MessageType   { Command = 0x00, Phase = 0x01, Sensor = 0x02 };
};