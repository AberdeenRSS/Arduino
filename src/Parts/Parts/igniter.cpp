#include "igniter.h"
#include <Arduino.h>
#include "myarduino.h"

Igniter::Igniter() : APart(0x02, true, 0.1) { 
        pinMode(IgniterPin, OUTPUT);
        digitalWrite(IgniterPin, LOW);

        addCommand(this,  0x00, [](Igniter* t) { return t->ignite(); });
}

void Igniter::update() {

    // Turn off igniter pin after ignitionOnMillis
    if(millis() > (lastIgniteMillis + ignitionOnMillis)){
        lastIgniteMillis = 0;
        digitalWrite(IgniterPin, LOW); 
    }

}

char Igniter::ignite() {
    digitalWrite(IgniterPin, HIGH);  
    lastIgniteMillis = millis();

    return Errors::Success;
}

