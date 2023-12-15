#pragma once

#include <Servo.h>
#include "Parts/AParts/apart.h"

class MyServo : public APart<MyServo, 2> {
public:
  MyServo();
  
private:
  Servo      myservo; 
  int        closedPos; 
  int        openPos;

  static const int ServoPin = 4;

private:
  char close();
  char open();
};
