#ifndef SoftMS_H
#define  SoftMS_H
#include "PID.h"
#include "SoftM.h"
#include "SoftS.h"

class SoftMS : public SoftM
{
public:
    inline SoftMS(byte pin1, byte pin2, SoftS* sensor, PID* pid, float touchvalue)
    {
        _pin1 = pin1;
        _pin2 = pin2;
        _sensor = sensor;
        _lastval=0;
        _pid=pid;
        _touchvalue=touchvalue;
    }

    void loop();
    void setup();
    void inflate();
    void deflate();
    void hold();

private:
    SoftS* _sensor;
    PID* _pid;
    int _touchvalue;
    int _lastval;

};


#endif //SoftMS_H