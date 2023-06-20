#pragma once

#include <Arduino.h>


// namespace RSS {
//     namespace HdlcSerial {

        struct RSSPacket {

            /**
             * The index of the message. (Rolls over)
            */
            u8 index;

            /**
             * The command to execute
            */
            u8 command;

            /**
             * Actual length of the payload
            */
            size_t payloadLength;

            /**
             * Payload of the packet (any additional data)
            */
            u8 payload[48];
            
        };
        

        void startHardwareSerial(void (*on_receive_callback)(RSSPacket &pkt));

        void runRead();

        void write(RSSPacket& packet);

//     }
// }

