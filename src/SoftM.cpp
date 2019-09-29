#include "SoftM.h"
#include "Arduino.h"

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

void SoftM::reset(){
    SoftM::purge();
    SoftM::_idle();
}

boolean SoftM::ready()
{
    return _isDone;
}
