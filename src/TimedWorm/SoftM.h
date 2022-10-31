#ifndef SoftM_h
#define SoftM_h

#include "Arduino.h"

class SoftM
{

    public:

    SoftM();
    ~SoftM();
    virtual void assign_pins(); 
    virtual void inflate();
    virtual void deflate();
    virtual void hold(); 
    virtual void actuate(); 
    virtual bool isDone();
    virtual void SM_setup();

};

#endif //SoftM;