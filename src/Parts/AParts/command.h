#pragma once

struct LaunchPhase{

    enum StateEnum {
        Init                = (1 << 0),
        Preparation         = (1 << 1),
      //  Instalation         = (1 << 1),
      //  FinalPreparation    = (1 << 2),
        Ignition            = (1 << 2),
        LiftOff             = (1 << 3),
     // Coasting            = (1 << 5),
     // Apogee              = (1 << 6),
        Recovery            = (1 << 4)
    };
};

inline LaunchPhase::StateEnum launchPhase = LaunchPhase::Init;
//inline LaunchPhase::StateEnum launchPhase = LaunchPhase::Preparation;

template<class T>
class Command {
public:
    Command() : ptr(nullptr) {}

public:
    T* ptr;
    char code;
    char(*fun)(T*);
    int flags;
};
