//#include <Servo.h>
//#include <Time.h>
//#include <TimerOne.h>

#include<iostream>
#include<fstream>
#include <cmath>
//#include "clock.h"
using namespace std;
double x1, x2, x3, x4, x5, x6, y1n, y2, y3, y4, y5, y6, margin, d;
double currX=0, currY=0, currR=0, curTheta=0, currPhi=0, dx, dy, dphi;
const double dtheta=.001;
const double dr=0.0001;
const double L=0.15;
ofstream myfilex;
ofstream myfiley;
void moveR(double r)
{
    //given an r, the function moves the bot to the given r.
    //double phi=servoPhi.read();
    //dphi=r/(-2*L*sin(phi));
    //servoPhi.write(phi+dphi);
    myfilex<<currX<<"\n";
    myfiley<<currY<<"\n";
}

void moveTheta(double dthe)
{
    //given a theta, the function moves the bot to the given theta.
    //double theta=giveTheta(currX,currY);
    //servoTheta.write(theta+dthe);
    cout<<currX<<"   "<<currY<<"\n";
}
double giveR(double x, double y)
{
    //giveR and giveTheta give r and theta if input is x and y. (conver cartesian coordinates to radial coordinates.)
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

void moveX(double X)
{
  //This, along with moveY, is the main function of the project. moveX will move the arm of the bot to the given X coordinate.

  double x_in,y_in,i,count,r,theta;//assuming X,Y to be instance or global variables
  x_in=currX;
  y_in=currY;
  count=0;
  r=giveR(x_in,y_in);//changing to polar co-ordinates
  theta=giveTheta(x_in,y_in);//changing to polar co-ordinates
  dx=dr*cos(theta)-r*dtheta*sin(theta);//relation b/w dx,dr and dtheta
  //this block consider the case that the bot is at an x lower than X
  if(x_in<X)
    for(i=x_in;i<=X;i+=dx)//right to left
    {
      int mov=pow(+1,count++)*dr;
      moveR(mov);
      moveTheta(dtheta);
      currX-=dx;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dx=dr*cos(theta)-r*dtheta*sin(theta);
      if (currX>X)
        break;
    }
   else
  //this block consider the case that the bot is at an x higher than X
    for(i=x_in,count=0;i>=X;i-=dx)//left to right
    {
      int mov=pow(+1,count++)*dr;
      moveR(mov);
      moveTheta(-1*dtheta);
      currX+=dx;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dx=dr*cos(theta)-r*dtheta*sin(theta);
      if (currX<X)
        break;
    }
   x_in+=dx;

}
void moveY(double Y)
{
  double x_in,y_in,i,count,r,theta;//assuming X,Y to be instance or global variables
  x_in=currX;
  y_in=currY;
  count=0;
  r=giveR(x_in,y_in);//changing to polar co-ordinates
  theta=giveTheta(x_in,y_in);//changing to polar co-ordinates
  dy=dr*sin(theta)+r*dtheta*cos(theta);//relation b/w dy,dr and dtheta
  if(y_in<Y)
  //this block consider the case that the bot is at an y lower than Y
    for(i=y_in;i<=Y;i+=dy)//up to down
    {
      int mov=pow(+1,count++)*dtheta;
      moveR(dr);
      moveTheta(mov);
      currY+=dy;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dy=dr*sin(theta)+r*dtheta*cos(theta);
      if (currY>Y)
        break;
    }
   else
  //this block consider the case that the bot is at an y higher than Y
    for(i=y_in,count=0;i>=Y;i-=dy)//down to up
    {
      int mov=pow(+1,count++)*dtheta;
      moveR(dr);
      moveTheta(-1*mov);
      currY-=dy;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dy=dr*sin(theta)+r*dtheta*cos(theta);
      if (currY<Y)
        break;
    }
   y_in+=dy;

}




void penUp(void)
{
    //Lifts the pen up.
    //delay(1000);
    //servoPenupdown.write(30);
    //delay(1000);
    //cout<<currX<<"   "<<currY<<"\n";
}

void penDown(void)
{
    //keeps the pen down
    //delay(1000);
    //cout<<currX<<"   "<<currY<<"\n";
    //servoPenupdown.write(-30);
    //delay(1000);

}

/*void initTime(int h, int m, int s)
{
    //Part of the initialisation settings; Setup time at startup of the bot.
    setTime(h, m, s, 1, 1, 2015);
    //Set the current time in this function before programming to the current time.
}
void updateTime(long s)
{
    //Setup timer and s is length of timer.
    //This function will be called at the end of every iteration of while loop.
     Will set the current time in the time variable.
    long sec2=second()+s;
    long minut2=minute();
    long hr2=hour();
    while(sec2>59)
    {
        minut2++;
        sec2=sec2-60;
    }
    while(minut2>59)
    {
        hr2++;
        minut2=minut2-60;
    }
    while(hr2>23)
    {
        hr2=hr2-24;
    }
    initTime(hr2, minut2, sec2);
}


 makeColon()
{
     moveY((y1n+y3)/2);
     moveX(x1-margin);
     moveX(x1+2*margin);
     moveX(x1);
     moveY((y3+y5)/2);
     moveX(x1-margin);
     moveX(x1+2*margin);
     moveX(x1);
     moveY(y1);

}*/
void make0()
{
	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	penDown();
	moveX(x2);
	moveY(y6);
	moveX(x5);
	moveY(y1n);
    moveX(x2);
}

void make1()
{
	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	moveX(x2);
	penDown();
	moveY(y6);
    moveY(y2);

}

void make2()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	penDown();
	moveX(x2);
	moveY(y4);
	moveX(x3);
	moveY(y5);
	moveX(x6);
    moveX(x6+margin);
    moveY(y2);

}

void make3()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	penDown();
	moveX(x2);
	moveY(y4);
	moveX(x3);

	penUp();
	moveX(x4);

	penDown();
	moveY(y6);
	moveX(x5);
	moveX(x6);
	moveY(y2);

}


void make4()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	penDown();
	moveY(y3);
	moveX(x4);

	penUp();
	moveY(y2);

	penDown();
	moveY(y6);
	moveY(y2);


}

void make5()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	moveX(x2);

	penDown();
	moveX(x1);
	moveY(y3);
	moveX(x4);
	moveY(y6);
	moveX(x5);
	moveX(x6+margin);
	moveY(y2);

}


void make6()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	moveX(x2);

	penDown();
	moveX(x1);
	moveY(y5);
	moveX(x6);
	moveY(y4);
	moveX(x3);
	moveX(x4+margin);
    moveY(y2);
}


void make7()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	moveX(x2);
	moveY(y6);
	moveY(y2);

}

void make8()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	moveY(y3);

	penDown();
	moveY(y5);
	moveX(x6);
	moveY(y4);
	moveX(x3);
	moveY(y1n);
	moveX(x2);
	moveY(y4);
	moveY(y2);
}

void make9()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1n);	// start point of number

	moveX(x2);
	moveY(y4);

	penDown();
	moveX(x3);
	moveY(y1n);
	moveX(x2);
	moveY(y6);
    moveY(y2);
}

void make(char ch)
{
    //takes in a character input and calls the function to print that particular character.
    switch(ch)
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
    //case ':' :
    //makeColon();
    }
}
void printTime(void)
{
    //prints the current time. Adjustments like margin and cell design can be changed here.
    //int sec1=second();
    //int minut1=minute();
    //int hr1=hour();
    int ch1, ch2, ch3, ch4;
    /*if(hr1<10)
    {
        ch1=0;
    }
    else
        ch1=hr1/10;
    ch2=hr1%10;
    if(minut1<10)
    {
        ch3=0;
    }
    else
        ch3=minut1/10;
    ch4=minut1%10;*/
    ch1=1;ch2=2;ch3=3;ch4=4;

    make(ch1);
    x1=x1+d;
    x2=x2+d;
    x3=x3+d;
    x4=x4+d;
    x5=x5+d;
    x6=x6+d;


    make(ch2);
    x1=x1+d;
    x2=x2+d;
    x3=x3+d;
    x4=x4+d;
    x5=x5+d;
    x6=x6+d;

    make(':');

    make(ch3);
    x1=x1+d;
    x2=x2+d;
    x3=x3+d;
    x4=x4+d;
    x5=x5+d;
    x6=x6+d;


    make(ch4);
    moveY(y2+margin);
    x1=x1-3*d;
    x2=x2-3*d;
    x3=x3-3*d;
    x4=x4-3*d;
    x5=x5-3*d;
    x6=x6-3*d;



}

void make_line()
{
    //A test function.
    moveX(-1);
}
void goTO(double x, double y)
{
    //another test function. this function moves the arm to x, y.
    //This function is not extensively tested as it is not used in the actual plotclock.
    double deltaX, deltaY, deltaX1, deltaY1;
    int i=0;
    deltaX=x-currX;
    deltaX1=deltaX/100;
    deltaY=y-currY;
    deltaY1=deltaY/100;
    for (i=0;i<100;i++)
    {
        moveX(currX+deltaX1);
        moveY(currY+deltaY1);
    }
}



//Servo servoPhi;
//Servo servoTheta;
//Servo servoPenupdown;

/*
This code is a simulation of the actual code on a pc. It will output the trajectory of the mechanical arm of the bot.
The bot must be given information in Theta and Phi, the angles for motion of the arms of the bot.
However, the coding has been done in cartesian coordinates and they have been converted to theta and phi, to simplify coding.
*/
//x1, x2...x6 and y1, y2... y6 are the x and y coordinates of the points required to create the number (think seven segment display.)
//margin is a redundant variable as of now but can be used to create margins in an imrovement of the project. d is the breadth of the cell
//and L is the lenngth of the arms. dheta and dr may be adjusted to improve accuracy in the printed text.


/*double interruptCounter;
int sec, minut, hr;
int servoPenupdownpin=11;*/

/*ISR (TIMER0_COMPA_vect)
{
    Interrupt service routine. this interrupt gets called upon every overflow of the timer, every 0.5 milliseconds.
    interruptCounter++;
}*/


//Servo servoPhi;
//Servo servoTheta;
//volatile int interruptCounter;

/*void setup
{
    int sec, minut, hr;
    //servoPhi.attach(9);
    //servoTheta.attach(10);
    //initTime(14, 15, 0);//time at which ic is bing swtiched on. HHMMSS in 24 hr format.
    //set timer1 interrupt at 1Hz
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    interruptCounter=0;
}
void loop
{
    sec=second(), minut=minute(), hr=hour();
    if (minut%5==0)
    {
        printTime();
    }
    else
    {
        delay(10);
    }
    //updateTime(interruptCounter);
    //interruptCounter=0;
}*/

int main()
{
    myfilex.open("dumpx.txt");
    myfiley.open("dumpy.txt");
    goTO(1,1);
    myfilex.close();
    myfiley.close();
}
