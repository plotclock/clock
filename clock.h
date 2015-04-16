#ifndef _CLOCK_H
#define _CLOCK_H
//variables
double currX, currY, currR, curTheta, currPhi, dx, dy, dphi;
const double dtheta=1.5;
const double dr=0.001;
const double L=0.15;//length of arm is 15 cm

//functions
double giveR(double x, double y);
double giveTheta(double x, double y);
void goTO(double x, double y);
void moveX(double X);
void moveY(double X);
void moveR(double r);
void moveTheta(double t);
void currentPosition(void);
void make(char); // input 0, 1, 2...9 or : to draw it
void make0(void);
void make1(void);
void make2(void);
void make3(void);
void make4(void);
void make5(void);
void make6(void);
void make7(void);
void make8(void);
void make9(void);
void makeColon(void);
void initTime(int h, int m, int s);
void updateTime(int s); // see if arduino has default library
void printTime(void);
void eraseText(void);
void penUp(void);
void penDown(void);
#endif
