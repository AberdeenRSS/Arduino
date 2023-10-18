#include "marduino.h"
#include "Serial/ourserial.h"
#include "Messages/sensormessage.h"
#include "errors.h"
MArduno::MArduno() : APart(0x00, true) {
    addCommand(this,  0x00, [](MArduno* t) { return t->resetArduino(); });
    addCommand(this,  0x01, [](MArduno* t) { return t->startPreparationPhase(); },  LaunchPhase::Init | LaunchPhase::Ignition   );
    addCommand(this,  0x02, [](MArduno* t) { return t->startIgnitionPhase();    },  LaunchPhase::Init | LaunchPhase::Preparation);
    addCommand(this,  0x03, [](MArduno* t) { return t->startLiftoffPhase();     },  LaunchPhase::Init | LaunchPhase::Ignition   );
    addCommand(this,  0x04, [](MArduno* t) { return t->startRecoveryPhase();    },  LaunchPhase::Init | LaunchPhase::LiftOff    );
}

char MArduno::resetArduino() {
    resetFunc();
    return Errors::Success;
}

char MArduno::startPreparationPhase() {
    launchPhase = LaunchPhase::Preparation;

    updateState = false;

    return Errors::Success;
}

char MArduno::startIgnitionPhase() {
    launchPhase = LaunchPhase::Ignition;
    return Errors::Success;
}

char MArduno::startLiftoffPhase() {
    launchPhase = LaunchPhase::LiftOff;
    return Errors::Success;
}

char MArduno::startRecoveryPhase(){
    launchPhase = LaunchPhase::Recovery;
    return Errors::Success;
}

void MArduno::update(){
    LaunchPhaseMessage::sendMessage();
}