#ifndef SoftS_H
#define SoftS_H

#include <Arduino.h>

class SoftS
{
public:
    SoftS(byte pin,unsigned long sampler){
        _sampler=sampler;
        _pin=pin;
    };
    void setup();
    void loop();
    void getData(unsigned long sampleval);
    float derivate();
    int value();
private:
    byte _pin;
    unsigned long _timer;
    unsigned long _sampler;
    int _value;
    int _lastvalue;
    float _derivative;
};

#endif // SoftS_H