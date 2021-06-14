#include "SoftPWM.h"

void setup() {
  // put your setup code here, to run once:
  SoftPWMBegin();
  SoftPWMSet(0, 0);
  SoftPWMSetFadeTime(0, 100, 500);
}

void loop()
{
  // Turn on - set to 100%
  SoftPWMSetPercent(1, 100);

  // Wait for LED to turn on - you could do other tasks here
  delay(100);

  // Turn off - set to 0%

  // Wait for LED to turn off
  delay(10000);
  SoftPWMSetPercent(1,0);
  delay(10000);
  SoftPWMSetPercent(0,100);
  delay(10000);
  SoftPWMSetPercent(0,100);
  delay(10000);
  
}
