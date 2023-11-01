#pragma once

#include "apart.h"
#include "Messages/sensormessage.h"
#include <Arduino.h>

template<class T>
class ASensor : public APart<T> {
public:
    explicit ASensor(char code, int updateSpeedRate = 1) 
        : APart<T>(code),
          updateSpeed(1000 * updateSpeedRate) {}

    virtual char read_data() = 0;


    virtual char fun(char c) override {
        char result = Errors::Success;

        if(nextReading <= millis()) {
            result = APart<T>::fun(c);
            nextReading = millis() + updateSpeed;
        }

        return result;
    }

    char send_Message(float data, char sensorDataPart = 0x01) {
        return  SensorMessage::sendMessage(this->getCode(), data, sensorDataPart);
    }

    void setUpdateSpeed(int s = 1) {
        updateSpeed = s * 1000;
    }

private:
    int updateSpeed;

    unsigned long nextReading;
};
