#include "igniter.h"
#include <Arduino.h>



Igniter::Igniter() 
    : state(Ready),
      currentMillis(0) { }

void Igniter::init() {
    pinMode(IgniterPin, OUTPUT);
}

int Igniter::action(char c) {
    if (c == IgniteCommand)
        digitalWrite(IgniterPin, HIGH);   
        state = Ignited;
        currentMillis = millis();
        return 1;

    return 0;
}

void Igniter::update() {
    if (state == Ignited) {
        if(millis() - currentMillis > timeDelay) {
            digitalWrite(IgniterPin, LOW);  
            state = Finished;
        }
    }
}