#include "Arduino.h"
#include "PID.h"

int error;
int lasterror;
int sumerror;
int integral;
int correction;

int PID::pidout(int target, int value)
{
    if (millis() - _timer >= _dt)
    {
        _timer = millis();
        error = target - value;
        int proportional = error * _kp;
        float derivative = _kd * ((float(error - lasterror)) / float(_dt));
        lasterror = error;
        if (abs(target - value) <= pidon)
        {
            sumerror = sumerror + error;
            integral = _ki * sumerror;
        }
        else
        {
            sumerror = 0;
            integral = 0;
        }
        correction = proportional + derivative + integral;
        correction = constrain(correction, 0, 255);
    }
    return correction;
}

void PID::setPID(int kp, int ki, int kd, int intthres, unsigned long dt)
{
    _kp = kp;
    _ki = ki;
    _kd = kd;
    pidon = intthres;
    _dt = dt;
}