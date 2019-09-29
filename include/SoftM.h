#ifndef SoftM_H
#define SoftM_H

#include <Arduino.h>

class SoftM
{
public:
    inline virtual void begin(){};
    virtual void setup();
    void purge();
    boolean ready();
    void _idle();
    virtual void inflate(){};
    virtual void deflate(){};
    virtual void loop();
    void reset();
    enum States
    {
        idle = 0,
        inflating = 1,
        deflating = 2,
        holding = 3
    } _state;
    byte _pin1;
    byte _pin2;
    boolean _isDone;
};

#endif // SoftM_H