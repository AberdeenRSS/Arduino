#include "reset.h"
#include <Arduino.h>

int Reset::action(char c) {
    if (c == ResetArduino)
        resetFunc();

    return 0;
}

void Reset::init() {

}