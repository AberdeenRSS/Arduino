#pragma once

#include "Parts/AParts/apart.h"

class PartName : public APart<PartName, 1> {
public:
  PartName();
  
private:
  char commandFunction();
};
