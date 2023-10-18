#include "templatePart.h"

PartName::PartName()
    : APart(0x01) {


        addCommand(this,  0x00, [](PartName* t) { return t->commandFunction(); }, LaunchPhase::Preparation | LaunchPhase::LiftOff | LaunchPhase::Recovery);
}

char PartName::commandFunction() {
    return Errors::Success;
}




