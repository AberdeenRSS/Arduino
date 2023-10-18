#pragma once

enum Errors {
    Success                  = 0x00,

    IncompatibleLaunchPhase  = 0x01,

    WrongStartByte           = 0x10,
    WrongConnectionByte      = 0x11,
    WrongStateByte           = 0x12,
    WrongPartByte            = 0x13,
    WrongCommandByte         = 0x14,
    WrongEndByte             = 0x15
};