#pragma once

class State;

class Interface {
public:
    virtual char fun(char) = 0;
    virtual ~Interface() = default;

    virtual char getCode() const = 0;
    virtual void update() {}
    virtual bool moreUpdate() = 0;
    virtual int  getUpdatesSpeed() = 0;


protected:
   // virtual void defineCommands() = 0;
};