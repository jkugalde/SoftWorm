#ifndef SWorm_H
#define SWorm_H
#include <Arduino.h>
#include "SoftMT.h"

class SWorm{
public:
SWorm(SoftM* M1, SoftM* M2){
_M1=M1;
_M2=M2;
};
void forward();
void backward();
void idle();
private:
SoftM*_M1;
SoftM*_M2;
};

#endif //SWorm_H