#include <clock.h>

Servo servoPhi;
ServoTheta;
volatile int interruptCounter;

ISR (TIMER1_COMPA_vect)
{
    interruptCounter++;
}

void setup
{
    int sec, minut, hr;
    servoPhi.attach(9);
    servoTheta.attach(10);
    initTime(14, 15, 0);//time at which ic is bing swtiched on. HHMMSS in 24 hr format.
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
    updateTime(interruptCounter);
    interruptCounter=0;
}

