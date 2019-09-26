#include "SoftMS.h"
#include "SoftM.h"
#include "Arduino.h"

void SoftMS::inflate()
{
    _state = inflating;
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
    _isDone = false;
}

void SoftMS::deflate()
{
    _state = deflating;
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    _isDone = false;

}

void SoftMS::loop(){

}
