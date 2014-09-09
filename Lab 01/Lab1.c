// Lab1Main.c
// Runs on LM4F120/TM4C123
// Test the functions in ST7735.c by printing basic
// patterns to the LCD.
// Omar Marawi Keith Cyr
// September 4, 2014 #include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include "string.h"
#include "ST7735.h"
#include "PLL.h"
#include "fixed.h"
#include "inc/tm4c123gh6pm.h"

int main(void){ // possible main program that tests your functions
  PLL_Init();
  ST7735_InitR(INITR_REDTAB);
  for(int i=0; i<110000; i=i+902)
  {
			printf("%d gives: ", i);
      Fixed_uDecOut2(i);
  }
/*  for(int i=-11000; i<11000; i=i+71)
  {
			printf("%d gives: ", i);
      Fixed_sDecOut3s(i);
  }
  for(int i=0x00; i<110000; i=i+0xA21)
  {
			printf("%d gives: ", i);
      Fixed_uBinOut8(i);
  }*/
}
