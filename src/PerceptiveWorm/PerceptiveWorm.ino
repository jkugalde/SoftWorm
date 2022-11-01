#include "SWorm.h"

Perceptive_SM * head;
Timed_SM * body;
Perceptive_SM * tail;

SWorm Worm;

const int headpins[3] = {3,2,A0};
const int bodypins[2] = {6,5};
const int tailpins[3] = {9,13,A1};

const float slopevalshead[2] = {30,2};
const float slopevalstail[2] = {25,2};

const float head_pidks[3]={1.0,0.1,0};
const float tail_pidks[3]={1.0,0.1,0};

unsigned long bodytimes[2] = {1000,1000};

void setup() {

  head = new Perceptive_SM();
  head -> assign_pins(headpins);
  head -> setslopevals(slopevalshead);
  head -> setpid(head_pidks);
  body = new Timed_SM();
  body -> assign_pins(bodypins);
  body -> set_times(bodytimes);
  tail = new Perceptive_SM();
  tail -> assign_pins(tailpins);
  tail -> setslopevals(slopevalstail);
  tail -> setpid(tail_pidks);
  
  Serial.begin(9600);

  Worm.registerSMs(head,body,tail);
  Worm.setup();

}

void loop() {

Worm.moveForward();
Worm.actuate();

}