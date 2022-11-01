#ifndef Perceptive_SM_h
#define Perceptive_SM_h

#include "SoftM.h"

class Perceptive_SM: public SoftM{

  public:

  Perceptive_SM();
  ~Perceptive_SM();
  void SM_setup();
  void assign_pins(int pins[3]);
  void actuate();
  void inflate();
  void deflate();
  void hold();
  void readSens();
  bool isDone();
  void setpid(float pidks[3]);
  void setslopevals(float vals[2]);
  void PID(float target);
  float slope();

  private:

  int _pinC;
  int _pinV;
  int _pinS;
  int _Cstate;
  float _kp;
  float _kd;
  float _ki;
  float _ierror;
  float _lasterror;
  float _sensval;
  float _lastsens;
  float _anchorval;
  float _touchpoint;
  float _steadyval;
  bool _Vstate;
  unsigned long _timer;
  bool _done;

};

#endif