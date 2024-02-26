#include "marduino.h"
#include "Serial/ourserial.h"
#include "Messages/sensormessage.h"
#include "errors.h"
#include "Messages/commandmessage.h"
#include <Arduino.h>
#include "myservo.h"

MArduno::MArduno() : APart(0x00, true) {


    addCommand(this,  0x00, [](MArduno* t) { return t->resetArduino(); });
    addCommand(this,  0x01, [](MArduno* t) { return t->keepAlive(); });
}

char MArduno::resetArduino() {
    resetFunc();
    return Errors::Success;
}

char MArduno::keepAlive(){
    this->lastKeepAliveMillis = millis();
    this->timeoutTriggered = false;
    return Errors::Success;
}

void MArduno::update(){

    if(!timeoutTriggered && millis() > (lastKeepAliveMillis + timeout)){
        timeoutTriggered = true;
        onTimeout();
    }
}

//Trigger parachute in case of timeout
void MArduno::onTimeout(){
    MyServo* servo = make_Sensor<MyServo>();
    servo->open();
}