#pragma once

#include "Serial/ourserial.h"

template <unsigned int PayloadL>
class SensorMessages
{
public:
    SensorMessages(char partID, unsigned int type)
        : i(0)
    {
        arr[0] = (partID & 127) << 1; // Cut off first bit (only 127 parts supported, as first bit is reserved for command type)
        arr[0] |= ((PayloadL -1) & 0b00010000) >> 4; // Payload length is split between byte 0 and 1: most significant bit goes here
        arr[1] = ((PayloadL -1) & 0b00001111) << 4; // rest here
        arr[1] |= type & 0b00001111;
    }

    void reset(){
        i = 0;
    }

    /// @brief Assigns the provide data to the message. WARNING: unsafe operation, be careful that the byte length match PayloadL defined beforehand
    /// @param data Raw data pointer
    /// @param length Length of the data to add
    void addData(int* data)
    {
        memcpy(arr + 2 + i, data, sizeof(int));
        i += sizeof(int);
    }

    /// @brief Assigns the provide data to the message. WARNING: unsafe operation, be careful that the byte length match PayloadL defined beforehand
    /// @param data Raw data pointer
    /// @param length Length of the data to add
    void addData(bool* data)
    {
        memcpy(arr + 2 + i, data, sizeof(bool));
        i += sizeof(bool);
    }

    /// @brief Assigns the provide data to the message. WARNING: unsafe operation, be careful that the byte length match PayloadL defined beforehand
    /// @param data Raw data pointer
    /// @param length Length of the data to add
    void addData(float* data)
    {
        memcpy(arr + 2 + i, data, sizeof(float));
        i += sizeof(float);
    }

    int getPart() const
    {
        unsigned char mask = 127;

        return arr[0] & mask;
    }

    void sendMessage()
    {
        OurSerial::sendPacket(arr, PayloadL + 2); // 2 header bytes + data
    }

private:
    unsigned char arr[PayloadL + 2];
    char i;
};