#include "Arduino.h"
#include "SoftMT.h"
#include "SOftMS.h"
#include "SoftS.h"
#include "SWorm.h"
#include "PID.h"


//timed version
/* SoftMT m1(2, 3, 1000, 1000);
SoftMT m2(4, 5, 1000, 1000);
SoftMT m3(6, 7, 1000, 1000);  */

//with sensors 
unsigned long samplerate=50;
SoftS s1(A0,samplerate);
SoftS s2(A1,samplerate);
PID p1(1,1,1,20,samplerate);
PID p2(1,1,1,20,samplerate);
SoftMS m1(2,3,&s1,&p1,1);
SoftMT m2(4,5,1000,1000);
SoftMS m3(6,7,&s2,&p2,1); 

SWorm worm(&m1,&m2,&m3); 


void setup()
{
Serial.begin(9600);
worm.setup();
}

void loop()
{
worm.forward();
worm.loop();
}
