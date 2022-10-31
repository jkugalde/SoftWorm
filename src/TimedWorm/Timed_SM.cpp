#include "Timed_SM.h"

Timed_SM::Timed_SM(){

  _Cstate=0;
  _Vstate=0;
  _done=false;
  _timer=0;

}

Timed_SM::~Timed_SM(){}

void Timed_SM::assign_pins(int pins[2]){

  _pinC=pins[0];
  _pinV=pins[1];

}

void Timed_SM::set_times(unsigned long times[2]){

  _itime=times[0];
  _dtime=times[1];

}

void Timed_SM::SM_setup(){

  pinMode(_pinC,OUTPUT);
  pinMode(_pinV,OUTPUT);
  digitalWrite(_pinC,LOW);
  digitalWrite(_pinV,LOW);

}

void Timed_SM::actuate(){

  digitalWrite(_pinC,_Cstate);
  digitalWrite(_pinV,_Vstate);

}

void Timed_SM::deflate(){

  if(_done==true){
    _timer=millis();
  }
  _Cstate=0;
  _Vstate=1;
  _done=false;
  if(millis()-_timer>=_dtime){
    _done=true;
  }

}

void Timed_SM::inflate(){

  if(_done==true){
    _timer=millis();
  }
  _Cstate=1;
  _Vstate=0;
  _done=false;
  if(millis()-_timer>=_itime){
    _done=true;
  }

}

void Timed_SM::hold(){

  _Cstate=0;
  _Vstate=0;

}



bool Timed_SM::isDone(){

  return _done;

}