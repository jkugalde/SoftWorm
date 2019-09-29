#include "SWorm.h"
#include "SoftMT.h"
#include "SoftM.h"
#include <Arduino.h>

void SWorm::forward(){
  if (_HEAD->ready() && _BODY->ready() && _TAIL->ready())
  {
    _step = (_step + 1) % 6;
    steps();
  }
}

void SWorm::backward(){
  if (_HEAD->ready() && _BODY->ready() && _TAIL->ready())
  {
    _step = (_step + 6 - 1) % 6;
    steps();
  }
}

void SWorm::_idle(){
    _HEAD->_idle();
    _BODY->_idle();
    _TAIL->_idle();
}

void SWorm::setup(){
    _HEAD->setup();
    _BODY->setup();
    _TAIL->setup();
}

void SWorm::steps(){
    switch (_step)
  {
  case 0: //exptail
    _TAIL->inflate();
    break;
  case 1: //defhead
    _HEAD->deflate();
    break;
  case 2: //expbod
    _BODY->inflate();
    break;
  case 3: //exphead
    _HEAD->inflate();
    break;
  case 4: //deftail
    _TAIL->deflate();
    break;
  case 5: //defbod
    _BODY->deflate();
    break;
  }
  Serial.println(_step);
}

void SWorm::reset(){
    _HEAD->reset();
    _BODY->reset();
    _TAIL->reset();

}

void SWorm::loop(){
    _HEAD->loop();
    _TAIL->loop();
    _BODY->loop();
}