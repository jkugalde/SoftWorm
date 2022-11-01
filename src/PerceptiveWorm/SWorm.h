#ifndef SWorm_h
#define SWorm_h

#include "Timed_SM.h"
#include "Perceptive_SM.h"

class SWorm{

  public:

  SWorm();
  ~SWorm();
  void setup();
  void registerSMs(SoftM * head, SoftM * body, SoftM * tail);
  void moveForward();
  void actuate();

  private:

  SoftM * _head;
  SoftM * _body;
  SoftM * _tail;
  int _state;

};

#endif