/*
This program will illustrate a simple interrupt program
*/

#include "mbed.h"

// Global Variable
unsigned short counter =0;  // set global variable counter to 0

InterruptIn pb(D6);         // cause interrupt based on PIR detector
DigitalOut red(LED1);       // red is set to red led
DigitalOut green(LED2);     // green is green led
DigitalOut blue(LED3);      // blue is set to blue led

void countmein(void)        // interrupt service routine
{
    counter++;              // add 1 to counter variable
}

int main (void)
{ 
   pb.fall(&countmein);     // when push button released executed countme in
  // pb.enable_irq();
   for(;;)
   {
        if(counter ==0)     // if counter variable is 0 then turn red on
        {
            green=blue=1;       // shut off green and blue leds
            red=0;              // turn on red led
        }
        else
          if(counter==1)    // if counter variable is 1 turn green led on
          {
              red=blue=1;       // turn off red and blue leds
              green=0;          // turn on green led
          }
          else
             if(counter==2) // if counter variable is 2 then turn on blue led
             {
                green=red=1;    // turn off green and red led
                blue=0;         // turn on blue led
           } 
           else 
           {
               counter=0;      // if counter out of range 0-2 reset to 0
              blue=1;
            //   pb.enable_irq();
            }
   }
 }