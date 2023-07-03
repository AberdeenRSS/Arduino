#pragma once

class Interface;

class MyArduino {
  enum Parts { Reset = 0, Servo, Igniter };

public:
  MyArduino();

  void init();
  int  action(int part, char command);
  void update();

private:
  static const int size = 3;
  Interface* arr[size];
};