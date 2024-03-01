#pragma once

#include "command.h"
#include "interface.h"
#include "errors.h"



template<class T, const int K>
class APart  : public Interface {
public:

    virtual char getCode() const override {
        return code;
    };

    virtual char fun(char c) override {
        for(int i = 0; i < commandCounter; ++i) {
            if (c == commands[i].code) {
                if(checkState(commands[i]))
                    return commands[i].fun(commands[i].ptr);
                else
                    return Errors::IncompatibleLaunchPhase;
            }
        }

        return Errors::WrongCommandByte;
    }

    virtual bool moreUpdate() override {
        return updateState;
    };

    virtual int getUpdatesSpeed() override {
        return updatesSpeed;
    }


protected:
    explicit APart(char c, bool updateS = false, double updatesS = 1) 
        :   updateState(updateS),
            updatesSpeed(updatesS * 1000),
            code(c), 
            commandCounter(0) {}

    void addCommand(T* ptr, char code, char(*fun)(T*), int flags = LaunchPhase::Preparation | LaunchPhase::Ignition
                                                                 | LaunchPhase::LiftOff     | LaunchPhase::Recovery ) {                                         
        commands[commandCounter].ptr = ptr;
        commands[commandCounter].code = code;
        commands[commandCounter].fun = fun;
        commands[commandCounter].flags = flags;
        ++commandCounter;
    }

protected:
    bool updateState;
    int updatesSpeed;

private:
    char code;
    int commandCounter;
    Command<T> commands[K];
    
private:
    bool checkState(const Command<T>& command) const {
        LaunchPhase::StateEnum* launchPhase = getLaunchPhase();
        return command.flags & (*launchPhase);
    }
};


