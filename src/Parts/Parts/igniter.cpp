#include "igniter.h"
#include <Arduino.h>


Igniter::Igniter() : APart(0x02) { 
        pinMode(IgniterPin, OUTPUT);
        digitalWrite(IgniterPin, LOW);

        addCommand(this,  0x00, [](Igniter* t) { return t->ignite(); }, LaunchPhase::Ignition);
        addCommand(this,  0x01, [](Igniter* t) { return t->igniteWithDelay();  }, LaunchPhase::Ignition);
}

char Igniter::ignite() {
    digitalWrite(IgniterPin, HIGH);  

    // uncomment 
    ////digitalWrite(IgniterPin, LOW);  

    launchPhase = LaunchPhase::LiftOff;

    return Errors::Success;
}

char Igniter::igniteWithDelay() {
    return Errors::Success;
}
