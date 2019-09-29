#ifndef SWorm_H
#define SWorm_H
#include <Arduino.h>
#include "SoftMT.h"

class SWorm{
public:
SWorm(SoftM* M1, SoftM* M2, SoftM* M3){
_TAIL=M1;
_BODY=M2;
_HEAD=M3;
_step=5;
};
void setup();
void forward();
void backward();
void loop();
void _idle();
void reset();
void steps();
private:
SoftM* _TAIL;
SoftM* _BODY;
SoftM* _HEAD;
byte _step;
};

#endif //SWorm_H