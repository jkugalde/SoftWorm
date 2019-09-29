#include "Arduino.h"
#include "SoftMT.h"
#include "SOftMS.h"
#include "SoftS.h"
#include "SWorm.h"

SoftMT m1(2, 3, 1000, 1000);
SoftMT m2(4, 5, 1000, 1000);
SoftMT m3(6, 7, 1000, 1000);

SWorm worm(&m1,&m2,&m3);

void setup()
{
 worm.setup();
}

void loop()
{
  worm.loop();
  worm.forward();
}
