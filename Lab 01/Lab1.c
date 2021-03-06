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
	
	uint32_t uDecOut2[8] = {
		0,
		12,
		345,
		678,
		910,
		99999,
		100000,
		1000000
		};
	
	for(int i=0; i<8; i++)
	{
		printf("%d gives:\n", uDecOut2[i]);
		Fixed_uDecOut2(uDecOut2[i]);
	}
/*  for(int i=0; i<110000; i=i+902)
  {
			printf("%d gives: ", i);
      Fixed_uDecOut2(i);
  }
  for(int i=-11000; i<11000; i=i+71)
  {
			printf("%d gives: ", i);
      Fixed_sDecOut3s(i);
  }
  for(int i=0x00000000; i<257000; i=i+0xA21)
  {
		  printf("Binary %d gives \n", i);
			int decimal_int = ((i * 100 + 128) / 256);
			printf("decimal %d, which\n", decimal_int);
		  printf("gives: ");
      Fixed_uBinOut8(i);
			printf("\n");
  }
*/
}
