#pragma once

#include <Servo.h>
#include "Parts/AParts/apart.h"

class MyServo : public APart<MyServo> {
public:
  MyServo();
  
private:
  Servo      myservo; 
  int        closedPos; 
  int        openPos;

  static const int ServoPin = 11;

private:
  char close();
  char open();
};
