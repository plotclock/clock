#include <Servo.h>

#include <Time.h>

#include <TimerOne.h>

#include <clock.h>

Servo servoPhi;
Servo servoTheta;
Servo servoPenupdown;

double x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6, margin, d;

double interruptCounter;
int sec, minut, hr;
int servoPenupdownpin=11;

ISR (TIMER0_COMPA_vect)
{
    interruptCounter++;
}

void moveR(double r)
{
    double phi=servoPhi.read();
    dphi=r/(-2*L*sin(phi));
    servoPhi.write(phi+dphi);
}

void moveTheta(double dthe)
{
    double theta=giveTheta(currX,currY);
    servoTheta.write(theta+dthe);
}

void penUp(void)
{
    //delay(1000);
    servoPenupdown.write(30);
    //delay(1000);
}

void penDown(void)
{
    //delay(1000);
    servoPenupdown.write(-30);
    //delay(1000);

}

void initTime(int h, int m, int s)
{
    //Part of the initialisation settings; Setup time at startup of the bot.
    setTime(h, m, s, 1, 1, 2015);
    //Set the current time in this function before programming to the current time.
}
void updateTime(long s)
{
    //Setup timer and s is length of timer.
    //This function will be called at the end of every iteration of while loop. Will set the current time in the time variable.
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

void printTime(void)
{
    int sec1=second();
    int minut1=minute();
    int hr1=hour();
    int ch1, ch2, ch3, ch4;
    if(hr1<10)
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
    ch4=minut1%10;


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
void makeColon()
{
     moveY((y1+y3)/2);
     moveX(x1-margin);
     moveX(x1+2*margin);
     moveX(x1);
     moveY((y3+y5)/2);
     moveX(x1-margin);
     moveX(x1+2*margin);
     moveX(x1);
     moveY(y1);

}
void make0()
{
	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	penDown();
	moveX(x2);
	moveY(y6);
	moveX(x5);
	moveY(y1);
    moveX(x2);
}

void make1()
{
	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);
	penDown();
	moveY(y6);
    moveY(y2);

}

void make2()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

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
	moveY(y1);	// start point of number

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
	moveY(y1);	// start point of number

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
	moveY(y1);	// start point of number

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
	moveY(y1);	// start point of number

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
	moveY(y1);	// start point of number

	moveX(x2);
	moveY(y6);
	moveY(y2);

}

void make8()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveY(y3);

	penDown();
	moveY(y5);
	moveX(x6);
	moveY(y4);
	moveX(x3);
	moveY(y1);
	moveX(x2);
	moveY(y4);
	moveY(y2);
}

void make9()
{

	penUp();
	moveX(x1);	//bring the pen to initial
	moveY(y1);	// start point of number

	moveX(x2);
	moveY(y4);

	penDown();
	moveX(x3);
	moveY(y1);
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
    case ':' :
    makeColon();
    }
}
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
  r=giveR(x_in,y_in);//changing to polar co-ordinates
  theta=giveTheta(x_in,y_in);//changing to polar co-ordinates
  dx=dr*cos(theta)-r*dtheta*sin(theta);//relation b/w dx,dr and dtheta
  if(x_in<X)
    for(i=x_in;i<=X;i+=dx)//right to left
    {
      int mov=pow(-1,count++)*dr;
      moveR(mov);
      moveTheta(dtheta);
      currX+=dx;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dx=dr*cos(theta)-r*dtheta*sin(theta);
    }
   else
    for(i=x_in,count=0;i>=X;i-=dx)//left to right
    {
      int mov=pow(-1,count++)*dr;
      moveR(mov);
      moveTheta(-1*dtheta);
      currX-=dx;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dx=dr*cos(theta)-r*dtheta*sin(theta);
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
    for(i=y_in;i<=Y;i+=dy)//up to down
    {
      int mov=pow(-1,count++)*dtheta;
      moveR(dr);
      moveTheta(mov);
      currY+=dy;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dy=dr*sin(theta)+r*dtheta*cos(theta);
    }
   else
    for(i=y_in,count=0;i>=Y;i-=dy)//down to up
    {
      int mov=pow(-1,count++)*dtheta;
      moveR(dr);
      moveTheta(-1*mov);
      currY-=dy;
      theta=giveTheta(x_in,y_in);
      r=giveR(x_in,y_in);
      dy=dr*sin(theta)+r*dtheta*cos(theta);
    }
   y_in+=dy;

}
void setup()
{
    cli();
    int sec, minut, hr;
    servoPhi.attach(9);
    servoTheta.attach(10);
    servoPenupdown.attach(11);
    initTime(14, 16, 0);//time at which ic is bing swtiched on. HHMMSS in 24 hr format.
  //set timer0 interrupt at 2kHz
    TCCR0A = 0;// set entire TCCR0A register to 0
    TCCR0B = 0;// same for TCCR0B
    TCNT0  = 0;//initialize counter value to 0
    // set compare match register for 2khz increments
    OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
    // turn on CTC mode
    TCCR0A |= (1 << WGM01);
    // Set CS01 and CS00 bits for 64 prescaler
    TCCR0B |= (1 << CS01) | (1 << CS00);   
    // enable timer compare interrupt
    TIMSK0 |= (1 << OCIE0A);
    interruptCounter=0;
    sei();
}
void loop()
{
    sei();
    sec=second(), minut=minute(), hr=hour();
    if (minut%5==0)
    {
        printTime();
    }
    else
    {
        delay(10);
    }
    updateTime(long(interruptCounter/2000));
    interruptCounter=0;
}


