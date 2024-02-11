#include "igniter.h"
#include <Arduino.h>
#include "myarduino.h"

Igniter::Igniter() : APart(0x02, false, 0.5) { 
        pinMode(IgniterPin, OUTPUT);
        digitalWrite(IgniterPin, LOW);

        addCommand(this,  0x00, [](Igniter* t) { return t->ignite(); });
}

void Igniter::update() {
    digitalWrite(IgniterPin, LOW); 

    updateState = false;
}

char Igniter::ignite() {
    digitalWrite(IgniterPin, HIGH);  

    updateState = true;
    MyArduino* myArduino = make_Sensor<MyArduino>();
    myArduino->addUpdateComponent(updatesSpeed + millis(), this);

    LaunchPhase::StateEnum* launchPhase = getLaunchPhase();
    *launchPhase = LaunchPhase::LiftOff;

    return Errors::Success;
}

