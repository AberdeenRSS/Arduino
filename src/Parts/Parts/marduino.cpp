#include "marduino.h"
#include "Serial/hdlc_serial.h"
#include "Messages/sensormessage.h"
#include "errors.h"
#include "Messages/commandmessage.h"
#include <Arduino.h>
#include "myservo.h"
#include "type_utils.h"

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
    MyServo* servo = getSingleton<MyServo>();
    servo->open();
}