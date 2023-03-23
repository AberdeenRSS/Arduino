#pragma once

#include <Servo.h>

class MyServo {
    enum ServoState { Closed = 0, Open };

public:

  MyServo();

  void init();

  void message() const;

  void close();

  void open();


private:
    Servo      myservo; 
    int        closedPos; 
    int        openPos;
    ServoState servoState;
};
