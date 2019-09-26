#include "SoftM.h"
#include "Arduino.h"

void SoftM::setup()
{
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    _state = idle;
    _isDone = true;
}

void SoftM::purge()
{
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    delay(1000);
    digitalWrite(_pin2, LOW);
}

void SoftM::_idle()
{
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
    _state = idle;
    _isDone = true;
}

boolean SoftM::ready()
{
    return _isDone;
}
