#include "Arduino.h"
#include "SoftMT.h"
#include "SoftS.h"

byte step = 5;

SoftMT m1(2, 3, 1000, 1000);
SoftMT m2(4, 5, 1000, 1000);
SoftMT m3(6, 7, 1000, 1000);

void assign()
{

  switch (step)
  {
  case 0: //exptail
    m1.inflate();
    break;
  case 1: //defhead
    m3.deflate();
    break;
  case 2: //expbod
    m2.inflate();
    break;
  case 3: //exphead
    m3.inflate();
    break;
  case 4: //deftail
    m1.deflate();
    break;
  case 5: //defbod
    m2.deflate();
    break;
  }
}

void toggler()
{
  if (m1.ready() && m2.ready() && m3.ready())
  {
    step = (step + 1) % 6;
    assign();
  }
}

void setup()
{
  m1.setup();
  m2.setup();
  m3.setup();
}

void loop()
{
  m1.loop();
  m2.loop();
  m3.loop();
  toggler();
}
