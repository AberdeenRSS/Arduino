#include "myservo.h"
#include <Arduino.h>

MyServo::MyServo()
    : myservo(),
      closedPos(141),
      openPos(90),
      servoState(Closed) {}

void MyServo::init() {
   myservo.attach(ServoPin);  // attaches the servo on pin 9 to the servo object
   myservo.write(closedPos);
}

int MyServo::action(char c) {
    switch (c)
    {
    case (CloseServo):
        close();
        break;

    case (OpenServo):
        open();
        break;
    
    default:
        return 0;
    }

    return 1;
}

void MyServo::message() const  {   
} 


void MyServo::close() {
    if (servoState == Open) {         
        myservo.write(closedPos);

        servoState = Closed;
    }
}

void MyServo::open() {
    if (servoState == Closed) {
        /*
        for (int i = closedPos; i <= openPos; ++i) {
            myservo.write(i);
            delay(15);
        }
        */
        myservo.write(openPos);

        servoState = Open;
    }
}




