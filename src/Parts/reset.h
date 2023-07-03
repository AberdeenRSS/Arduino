#pragma once

#include "interface.h"

class Reset : public Interface {
    enum Commands { ResetArduino = 0x01 };

public :
    virtual int  action(char) override;
    virtual void init()       override;

private:
    void(* resetFunc) (void) = 0;
};