#ifndef Perceptive_SM_h
#define Perceptive_SM_h

#include "SoftM.h"

class Perceptive_SM: public SoftM{

  public:

  Perceptive_SM();
  ~Perceptive_SM();
  void SM_setup();
  void attach_sensor();
  void assign_pin(int pins[3]);

  private:

  int _pinC;
  int _pinV;
  int _pinS;

};

#endif