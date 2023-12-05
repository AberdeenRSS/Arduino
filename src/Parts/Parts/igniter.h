#pragma once

#include "Parts/AParts/apart.h"

class Igniter : public APart<Igniter, 1> {
public:
    Igniter();
    void update();

private:
    static const int IgniterPin = 4;

private:
    char ignite();
};