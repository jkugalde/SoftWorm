#ifndef PID_H
#define PID_H
#include <Arduino.h>

class PID
{

public:
    PID(int kp, int kd, int ki, int intthres, unsigned long dt)
    {
        _kp = kp;
        _kd = kd;
        _ki = ki;
        pidon=intthres;
        _dt=dt;
    };
    int pidout(int target, int value);
    void setPID(int kp, int ki, int kd, int intthres, unsigned long dt);
    void reset();
private:
    int _kp;
    int _kd;
    int _ki;
    int pidon;
    unsigned long _dt;
    unsigned long _timer;
};

#endif