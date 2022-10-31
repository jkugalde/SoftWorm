#include "SWorm.h"

Timed_SM * head;
Timed_SM * body;
Timed_SM * tail;

SWorm Worm;

const int headpins[2] = {3,2};
const int bodypins[2] = {6,5};
const int tailpins[2] = {9,13};

unsigned long headtimes[2] = {1000,1000};
unsigned long bodytimes[2] = {1000,1000};
unsigned long tailtimes[2] = {1000,1000};


void setup() {

  head = new Timed_SM();
  head -> assign_pins(headpins);
  head -> set_times(headtimes);
  body = new Timed_SM();
  body -> assign_pins(bodypins);
  body -> set_times(bodytimes);
  tail = new Timed_SM();
  tail -> assign_pins(tailpins);
  tail -> set_times(tailtimes);
  
  Serial.begin(9600);

  Worm.registerSMs(head,body,tail);
  Worm.setup();

}

void loop() {

Worm.moveForward();
Worm.actuate();

}
