#include "SoftS.h"
#include "Arduino.h"


void SoftS::setup()
{
    pinMode(_pin, INPUT);
    _timer = millis();
    _derivative=0;
    _value=0;
    _lastvalue=0;
}

void SoftS::getData(unsigned long sampler)
{

    if (millis() - _timer >= sampler)
    {
        _lastvalue = _value;
        _value = analogRead(_pin);
        _timer = millis();
        _derivative=(float(_value-_lastvalue))/float(_sampler);
    }

}

float SoftS::derivate(){
    return _derivative;
}

int SoftS::value(){
    return _value;
    }

void SoftS::loop(){

SoftS::getData(_sampler);

}