#include "igniter.h"
#include <Arduino.h>


Igniter::Igniter() : APart(0x02) { 
        pinMode(IgniterPin, OUTPUT);
        digitalWrite(IgniterPin, LOW);

        addCommand(this,  0x00, [](Igniter* t) { return t->ignite(); }, LaunchPhase::Ignition);
}

char Igniter::ignite() {
    digitalWrite(IgniterPin, HIGH);  

    // uncomment 
    ////digitalWrite(IgniterPin, LOW);  
    LaunchPhase::StateEnum* launchPhase = getLaunchPhase();
    *launchPhase = LaunchPhase::LiftOff;

    return Errors::Success;
}

