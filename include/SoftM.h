#ifndef SoftM_H
#define SoftM_H

#include <Arduino.h>

class SoftM
{
public:
    inline virtual void begin(){};
    void setup();
    void purge();
    boolean ready();
    void _idle();
    enum States
    {
        idle = 0,
        inflating = 1,
        deflating = 2
    } _state;
    byte _pin1;
    byte _pin2;
    boolean _isDone;
};

#endif // SoftM_H