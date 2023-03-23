#include "myservo.h"
#include <Arduino.h>


#define ServoPin 8


MyServo::MyServo()
    : myservo(),
      closedPos(20),
      openPos(120),
      servoState(Closed) { }

void MyServo::init() {
   myservo.attach(ServoPin);  // attaches the servo on pin 9 to the servo object
   myservo.write(closedPos);
}

void MyServo::message() const  {   
} 


void MyServo::close() {
    if (servoState == Open) {
                

        for (int i = openPos; closedPos <= i; --i) {
            myservo.write(i);
            delay(15);
        }
           
        //myservo.write(closedPos);

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




