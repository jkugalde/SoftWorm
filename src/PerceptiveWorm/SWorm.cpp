#include "SWorm.h"

SWorm::SWorm(){

_state=0;

}

SWorm::~SWorm(){}

void SWorm::registerSMs(SoftM * head, SoftM * body, SoftM * tail){

 _head=head;
 _body=body;
 _tail=tail;

}

void SWorm::setup(){

  _head->SM_setup();
  _body->SM_setup();
  _tail->SM_setup();

}

void SWorm::moveForward(){

switch(_state){
  
  case 0:{
  _head->inflate();
  if(_head->isDone()==true){
    _state=_state+1;
    _head->hold();
  }
  break;
  }

  case 1:{
  _tail->deflate();
  if(_tail->isDone()==true){
    _state=_state+1;
    _tail->hold();
  }
  break;
  }

  case 2:{
  _body->deflate();
  if(_body->isDone()==true){
    _state=_state+1;
    _body->hold();
  }
  break;
  }

  case 3:{
  _tail->inflate();
  if(_tail->isDone()==true){
    _state=_state+1;
    _tail->hold();
  }
  break;
  }

  case 4:{
  _head->deflate();
  if(_head->isDone()==true){
    _state=_state+1;
    _head->hold();
  }
  break;
  }

  case 5:{
  _body->inflate();
  if(_body->isDone()==true){
    _state=0;
    _body->hold();
  }
  break;
  }

}
}

void SWorm::actuate(){

  _head->actuate();
  _body->actuate();
  _tail->actuate();

}