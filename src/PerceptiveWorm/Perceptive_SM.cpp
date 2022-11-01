#include "Perceptive_SM.h"

Perceptive_SM::Perceptive_SM(){

_timer=millis();
_lasterror=0;
_sensval=0;
_ierror=0;
_lastsens=5000;

}

Perceptive_SM::~Perceptive_SM(){}

void Perceptive_SM::assign_pins(int pins[3]){

_pinC=pins[0];
_pinV=pins[1];
_pinS=pins[2];

}

void Perceptive_SM::SM_setup(){

  pinMode(_pinC,OUTPUT);
  pinMode(_pinV,OUTPUT);
  pinMode(_pinS,INPUT);
  digitalWrite(_pinC,LOW);
  digitalWrite(_pinV,LOW);

}

void Perceptive_SM::setpid(float pidks[3]){

  _kp=pidks[0];
  _kd=pidks[1];
  _ki=pidks[2];

}

void Perceptive_SM::setslopevals(float vals[2]){

  _touchpoint=vals[0];
  _steadyval=vals[1];

}

void Perceptive_SM::actuate(){

  analogWrite(_pinC,_Cstate);
  digitalWrite(_pinV,_Vstate);
  _lastsens=_sensval;
  _sensval=analogRead(_pinS)*5000.0/1023.0;

}

void Perceptive_SM::PID(float target){
  
  float elapsedtime = millis()-_timer;
  float error=target-_sensval;
  float derror=(error-_lasterror)/elapsedtime;
  _ierror +=error*elapsedtime;
  _lasterror=error;
  _Cstate = int(_kp*error)+int(_kd*derror)+int(_ki*_ierror);
  _Cstate = constrain(_Cstate,0,255);
  _timer=millis();

}

void Perceptive_SM::inflate(){

  _Cstate=255;
  _Vstate=0;
  _done=false;
  if(slope()>=_touchpoint){
    _done=true;
    _anchorval=_sensval;
  } 

}

void Perceptive_SM::deflate(){

  _Cstate=0;
  _Vstate=1;
  _done=false;
  if(abs(slope())<=_steadyval){
    _done=true;
  } 

}

void Perceptive_SM::hold(){

  PID(_anchorval);
  _Vstate=0;

}

float Perceptive_SM::slope(){

  return _sensval-_lastsens;

}

bool Perceptive_SM::isDone(){

  return _done;

}
