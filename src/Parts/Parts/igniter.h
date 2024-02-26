#pragma once

#include "Parts/AParts/apart.h"

class Igniter : public APart<Igniter, 1> {
public:
    Igniter();
    void update();

private:
    static const int IgniterPin = 2;
    static const unsigned int ignitionOnMillis = 1000;

private:
    unsigned long lastIgniteMillis = 0;
    char ignite();
};