#ifndef SoftMS_H
#define  SoftMS_H

#include "SoftM.h"

class SoftMS : public SoftM
{
public:
    inline SoftMS(byte pin1, byte pin2)
    {
        _pin1 = pin1;
        _pin2 = pin2;
    }

    void loop();
    void inflate();
    void deflate();
    void hold();

private:

};


#endif //SoftMS_H