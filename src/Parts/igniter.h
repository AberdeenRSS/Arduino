#pragma once

#include "interface.h"


class Igniter : public Interface {
    enum Command { IgniteCommand = 0x01 };
    enum States  { Ready = 0, Ignited = 1, Finished = 2 };
public:
    Igniter();

    virtual void init() override;
    virtual int action(char) override;
    virtual void update() override;

private:
    States state;
    unsigned long currentMillis;

    static const int timeDelay = 300;
    static const int IgniterPin = 7;
};