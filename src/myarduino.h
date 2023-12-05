#pragma once

#define PartsCount 3
#define SensorsCount 2

#include <Arduino.h>
#include "AComponents/heap.h"
#include "AComponents/container.h"

class Interface;

class MyArduino {
public:
  void update();
  void read_data();

  char find(unsigned  char part, char code);

  void registerPart(Interface*r);
  void registerSensor(Interface*r);
  void addUpdateComponent(unsigned long nextUpdate, Interface* component);

private:  
  Heap<Wrapper<Interface*>> heap;
  Container array;
};