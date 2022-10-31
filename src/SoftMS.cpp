#include "SoftMS.h"
#include "SoftM.h"
#include "Arduino.h"
#include "PID.h"

void SoftMS::setup()
{
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    _state = idle;
    _isDone = true;
    _sensor->setup();
    Serial.println("Setup Done");
}

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

void SoftMS::hold()
{
    analogWrite(_pin1,_pid->pidout(_lastval,_sensor->value()));
}

void SoftMS::loop()
{
    _sensor->loop();
    switch (_state)
    {
    case inflating:
        if (_sensor->derivate() >= _touchvalue)
        {
            digitalWrite(_pin1, LOW);
            _lastval = (_sensor->value());
            _state = holding;
            _isDone = true;
            break;
        case deflating:
            if (_sensor->derivate() == 0)
            {
                SoftMS::_idle();
            }
            break;
        case holding:
            SoftMS::hold();
            break;
        case idle:
            /* do nothing */
            break;
        default:
            break;
        }
    }
}

