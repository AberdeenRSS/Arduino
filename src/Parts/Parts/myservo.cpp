#include "myservo.h"
#include <Arduino.h>

MyServo::MyServo()
    : APart(0x01),
      myservo(),
      closedPos(141),
      openPos(90) {

        myservo.attach(ServoPin);  // attaches the servo on pin 9 to the servo object
        myservo.write(closedPos);

        addCommand(this,  0x00, [](MyServo* t) { return t->close(); }, LaunchPhase::Preparation | LaunchPhase::LiftOff | LaunchPhase::Recovery);
        addCommand(this,  0x01, [](MyServo* t) { return t->open();  }, LaunchPhase::Preparation | LaunchPhase::LiftOff | LaunchPhase::Recovery);
}

char MyServo::close() {
    myservo.write(closedPos);
    return Errors::Success;
}

char MyServo::open() {
    myservo.write(openPos);
    return Errors::Success;
}




