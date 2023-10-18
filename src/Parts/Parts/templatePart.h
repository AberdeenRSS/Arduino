#pragma once

#include "Parts/AParts/apart.h"

class PartName : public APart<PartName> {
public:
  PartName();
  
private:
  char commandFunction();
};
