#pragma once

#define Parts 3
#define Sensors 2

class Interface;

class Container {
public:
  Container();

  void registerPart(Interface* part);
  void registerSensor(Interface* sensor);
  Interface* find(char partID) const;
  void read_data();

private:
  Interface* array[Parts + Sensors];
};