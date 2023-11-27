#pragma once

#include "apart.h"
#include "Messages/sensormessage.h"
#include <Arduino.h>

template<class T>
class ASensor : public APart<T, 1> {
public:
    explicit ASensor(char code, int updateSpeedRate = 1) 
        : APart<T, 1>(code),
          updateSpeed(1000 * updateSpeedRate) {}

    virtual char read_data() = 0;


    virtual char fun(char c) override {
        char result = Errors::Success;

        if(nextReading <= millis()) {
            result = APart<T, 1>::fun(c);
            nextReading = millis() + updateSpeed;
        }

        return result;
    }

    char send_Message(uint16_t data1, uint16_t data2, uint16_t data3) {
        SensorMessages sm(this->getCode(), 1, 3);
        sm.addData(data1);
        sm.addData(data2);
        sm.addData(data3);
        sm.sendMessage();
        return 0;
    }

    void setUpdateSpeed(int s = 1) {
        updateSpeed = s * 1000;
    }

private:
    int updateSpeed;
    unsigned long nextReading;
};
