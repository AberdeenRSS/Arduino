#pragma once

enum Errors {
    Success                  = 0x00,
    IncompatibleLaunchPhase  = 0x01,
    WrongPartByte            = 0x02,
    WrongCommandByte         = 0x03,
    JustWrong                = 0x04
};