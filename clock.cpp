#include "clock.h"
#include <math.h>
#include <Time.h>
double giveR(double x, double y)
{
    //Given the x and y coordinates, this function will return the value of r in radial coordinates.
    return sqrt(pow(x,2)+pow(y,2));
}
double giveTheta(double x, double y)
{
    //Given the x and y coordinates, this function will return the value of theta in radial coordinates.
    if(x!=0)
        return atan(y/x);
    else return 90;
}
void goTO(double x, double y)
{
    moveX(x);
    moveY(y);
}
void moveX(double X)
{
  double x_in,y_in,i,count,r,theta;//assuming X,Y to be instance or global variables
  x_in=currX;
  y_in=currY;
  count=0;
  r=getR(x_in,y_in);//changing to polar co-ordinates
  theta=getTheta(x_in,y_in);//changing to polar co-ordinates
  dx=dr*cos(theta)-r*dtheta*sin(theta);//relation b/w dx,dr and dtheta
  if(x_in<X)
    for(i=x_in;i<=X;i+=dx)//right to left
    {
      int mov=pow(-1,count++)*dr;
      moveR(mov);
      moveTheta(dtheta);
      x_in+=dx;
      theta=getTheta(x_in,y_in);
      r=getR(x_in,y_in);
      dx=dr*cos(theta)-r*dtheta*sin(theta);
    }
   else
    for(i=x_in,count=0;i>=X;i-=dx)//left to right
    {
      int mov=pow(-1,count++)*dr;
      moveR(mov);
      moveTheta(-1*dtheta);
      x_in-=dx;
      theta=getTheta(x_in,y_in);
      r=getR(x_in,y_in);
      dx=dr*cos(theta)-r*dtheta*sin(theta);
    }
   x_in+=dx;
   currX=x_in;
}
void moveY(double X)
{
  double x_in,y_in,i,count,r,theta;//assuming X,Y to be instance or global variables
  x_in=currX;
  y_in=currY;
  count=0;
  r=getR(x_in,y_in);//changing to polar co-ordinates
  theta=getTheta(x_in,y_in);//changing to polar co-ordinates
  dy=dr*sin(theta)+r*dtheta*cos(theta);//relation b/w dy,dr and dtheta
  if(y_in<Y)
    for(i=y_in;i<=Y;i+=dy)//up to down
    {
      int mov=pow(-1,count++)*dtheta;
      moveR(dr);
      moveTheta(mov);
      y_in+=dy;
      theta=getTheta(x_in,y_in);
      r=getR(x_in,y_in);
      dy=dr*sin(theta)+r*dtheta*cos(theta);
    }
   else
    for(i=y_in,count=0;i>=Y;i-=dy)//down to up
    {
      int mov=pow(-1,count++)*dtheta;
      moveR(dr);
      moveTheta(-1*mov);
      y_in-=dy;
      theta=getTheta(x_in,y_in);
      r=getR(x_in,y_in);
      dy=dr*sin(theta)+r*dtheta*cos(theta);
    }
   y_in+=dy;
   currY=y_in;
}
void make(char ch)
{
    //takes in a character input and calls the function to print that particular character.
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
void make0()
{
	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	//pendown
	moveX(x2);
	moveY(y6);
	moveX(x5);
	moveY(y1);
}

void make1()
{
	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);
	//pendown
	moveY(y6);

}

void make2()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	//pendown
	moveX(x2);
	moveY(y4);
	moveX(x3);
	moveY(y5);
	moveX(x6);

}

void make3()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	//pendown
	moveX(x2);
	moveY(y4);
	moveX(x3);

	//penup
	moveX(x4);

	//pendown
	moveY(y6);
	moveX(x5);

}


void make4()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	//pendown
	moveY(y3);
	moveX(x4);

	//penup
	moveY(y2);

	//pendown
	moveY(y6);


}

void make5()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);

	//pendown
	moveX(x1);
	moveY(y3);
	moveX(x4);
	moveY(y6);
	moveX(x5);

}


void make6()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);

	//pendown
	moveX(x1);
	moveY(y5);
	moveX(x6);
	moveY(y4);
	moveX(x3);
}


void make7()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);
	moveY(y6);
}

void make()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveY(y3);

	//pendown
	moveY(y5);
	moveX(x6);
	moveY(y4);
	moveX(x3);
	moveY(y1);
	moveX(x2);
	moveY(y4);
}

void make9()
{

	//penup
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);
	moveY(y4);

	//pendown
	moveX(x3);
	moveY(y1);
	moveX(x2);
	moveY(y6);
}

void initTime(int h, int m, int s)
{
    //Part of the initialisation settings; Setup time at startup of the bot.
    setTime(h, m, s, 1, 1, 2015);
    currentTime=now();
    //Set the current time in this function before programming to the current time.
}
void updateTime(int s)
{
    //Setup timer and s is length of timer.
    //This function will be called at the end of every iteration of while loop. Will set the current time in the time variable.
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
void printTime(void)
{
    int sec=second();
    int minut=minute();
    int hr=hour();
    int ch1, ch2, ch3, ch4;
    if(hr<10)
    {
        ch1=0;
    }
    else
        ch1=hr/10;
    ch2=hr%10;
    if(minut<10)
    {
        ch3=0;
    }
    else
        ch3=minut/10;
    ch4=minut%10;
}
