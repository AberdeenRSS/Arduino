#pragma once

#include "AComponents/bst.h"
#include "AComponents/heap.h"

class Interface;

class MyArduino {
public:
  void update();
  void read_data();

  char find(unsigned  char part, char code);
  void reg(Interface*r, bool updates = false);
  void addUpdateComponent(unsigned long nextUpdate, Interface* component);

  void show();

private:  
  BT<unsigned char, Interface*> bt;
  Heap<Wrapper<Interface*>> heap;
};