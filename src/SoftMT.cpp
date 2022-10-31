#include "SoftMT.h"
#include "SoftM.h"
#include "Arduino.h"

void SoftMT::setup()
{
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    _state = idle;
    _isDone = true;
    Serial.println("Setup Done");
}

void SoftMT::loop()
{

    if (millis() - _timer >= _processtime && _isDone == true)
    {
        SoftMT::_idle();
        _processtime=0;
        Serial.println(_state);
    }
}

void SoftMT::inflate()
{
    _state = inflating;
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
    _isDone = false;
    _timer = millis();
    _processtime = _inflationtime;
}

void SoftMT::deflate()
{
    _state = deflating;
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    _isDone = false;
    _timer = millis();
    _processtime = _deflationtime;
}

void SoftMT::setTimes(unsigned long inft, unsigned long dift)
{
 _inflationtime=inft;
 _deflationtime=dift;
}


