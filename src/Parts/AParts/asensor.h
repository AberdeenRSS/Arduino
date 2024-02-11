#pragma once

#include "apart.h"
#include "Messages/sensormessage.h"
#include <Arduino.h>

template<class T>
class ASensor : public APart<T, 1> {
public:
    explicit ASensor(char code, int updateSpeedRate = 1000) 
        : APart<T, 1>(code),
          updateSpeed(updateSpeedRate) {}

    virtual char read_data() = 0;


    virtual char fun(char c) override {
        char result = Errors::Success;

        if(nextReading <= millis()) {
            result = APart<T, 1>::fun(c);
            nextReading = millis() + updateSpeed;
        }

        return result;
    }



    void setUpdateSpeed(int s = 1) {
        updateSpeed = s * 1000;
    }

private:
    int updateSpeed;
    unsigned long nextReading;
};
