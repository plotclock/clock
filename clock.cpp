#include "clock.h"
#include <math.h>
#include "Time.h"

double giveR(double x, double y)
{
    return sqrt(pow(x,2)+pow(y,2));
}
double giveTheta(double x, double y)
{
    if(x!=0)
        return atan(y/x);
    else return 90;
}
void make(char ch)
{
    case '0' :
    make0();
    case '1' :
    make1();
    case '2' :
    make2();
    case '3' :
    make3();
    case '4' :
    make4();
    case '5' :
    make5();
    case '6' :
    make6();
    case '7' :
    make7();
    case '8' :
    make8();
    case '9' :
    make9();
    case ':' :
    makeColon();
}
void initTime(int h, int m, int s)
{
    setTime(h, m, s, 1, 1, 2015);
    currentTime=now();
    //Set the current time in this function before programming to the current time.
}
void updateTime(int s)
{
    //Setup timer and s is length of timer.
    int sec=second()+s;
    int minut=minute();
    int hr=hour();
    while(sec>59)
    {
        minut++;
        sec=sec-60;
    }
    while(minut>59)
    {
        hr++;
        minut=minut-60;
    }
    while(hr>23)
    {
        hr=hr-24;
    }
    initTime(hr, minut, sec);
    currentTime=now();
}
