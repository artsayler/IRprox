#include <stdio.h>
#include <unistd.h>
#include "c_gpio.c"

int main (void)
{
	  
  int ipin = 17; // physical pin 11
  int opin = 27; // physical pin 13

  int x;
  int debounce = 100;  /* 100 uSec */
  int latch_time = 1;  /* Latch on for 1 sec. */

  printf("Setting Up GPIO\n");
  
  setup();
 
  setup_gpio(ipin,INPUT, PUD_OFF);
  setup_gpio(opin,OUTPUT,PUD_OFF);
    
  x = 1;
  
 while(x) { // loop forever

// printf("%d\n",input_gpio(ipin)); /* uncomment for DEBUG */
	  
if(input_gpio(ipin)) { /* debounce loop */
	usleep(debounce); /* wait */
	if(input_gpio(ipin)) { 
		output_gpio(opin,HIGH); /* activate the "doorbell" */
		sleep(latch_time);      /* latch it on for 1 second */
			 }
	output_gpio(opin,LOW);		/* deactivate the "doorbell" */

			} // end debounce loop

  } // end forever loop

} //end main
