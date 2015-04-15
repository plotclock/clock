#include "clock.h"
Servo servoPhi;
ServoTheta;
int main (void)
{
    int sec, minut, hr;
    servoPhi.attach(9);
    servoTheta.attach(10);
    initTime(14, 15, 0);//time at which ic is bing swtiched on. HHMMSS in 24 hr format.
    while(1)
    {
        sec=second(), minut=minute(), hr=hour();

    }
