#pragma once

#include <Servo.h>
#include "interface.h"

class MyServo : public Interface {
  enum ServoState { Closed = 0, Open };

  enum Commands { CloseServo = 0x03,  OpenServo = 0x04 };

public:
  MyServo();

  void init();
  void message() const;

  virtual int action(char c) override;

private:
    Servo      myservo; 
    int        closedPos; 
    int        openPos;
    ServoState servoState;

    static const int ServoPin = 8;

private:
  void close();
  void open();
};
