#ifndef SoftMT_H
#define SoftMT_H
#include "SoftM.h"

class SoftMT : public SoftM
{
public:
    inline SoftMT(byte pin1, byte pin2, unsigned long inflationtime, unsigned long deflationtime)
    {
        _pin1 = pin1;
        _pin2 = pin2;
        _inflationtime = inflationtime;
        _deflationtime = deflationtime;
        _timer = 0;
        _processtime = 0;
    }
    void reset();
    void loop();
    void inflate();
    void deflate();
    void setTimes(unsigned long inft, unsigned long dift);

private:
    unsigned long _timer;
    unsigned long _inflationtime;
    unsigned long _deflationtime;
    unsigned long _processtime;
};

#endif // SoftMT_H