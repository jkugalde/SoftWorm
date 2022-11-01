#ifndef Timed_SM_h
#define Timed_SM_h

#include "SoftM.h"

class Timed_SM: public SoftM{

  public:

  Timed_SM();
  ~Timed_SM();
  void SM_setup();
  void set_times(unsigned long times[2]);
  void assign_pins(int pins[2]);
  void actuate();
  void inflate();
  void deflate();
  void hold();
  bool isDone();

  private:

  int _pinC;
  int _pinV;
  bool _Cstate;
  bool _Vstate;
  unsigned long _itime;
  unsigned long _dtime;
  unsigned long _timer;
  bool _done;

};

#endif