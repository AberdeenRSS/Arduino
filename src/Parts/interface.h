#pragma once

class Interface {
public :
    virtual int action(char c) = 0;
    virtual void init() = 0;
    virtual void update() {}
};