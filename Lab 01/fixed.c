// ************** fixed.c ************** 
// Lab 1 - Fixed point number manipulation
// Omar Marawi, Keith Cyr
// September 3, 2014

#include <stdio.h>
#include <stdint.h>

#define COUNT 5
/****************Fixed_uDecOut2***************
 converts fixed point number to ASCII string
 format unsigned 32-bit with resolution 0.01
 range 0 to 999.99
 Input: unsigned 32-bit integer part of fixed point number
         greater than 99999 means invalid fixed-point number
 Output: null-terminated string exactly 6 characters plus null
 Examples
 12345 to "123.45"  
 22100 to "221.00"
   102 to "  1.02" 
    31 to "  0.31" 
100000 to "***.**"    */ 
void Fixed_uDecOut2(uint32_t n)
{
	 char result[6];
	
   // check for valid input
   if(n > 99999)
   {
      result[5] = '*';
      result[4] = '*';
      result[3] = '.';
      result[2] = '*';
      result[1] = '*';
      result[0] = '*';

  	  printf("%s\n", result);
      return;
   }

   // deconstruct integer by dividing by 10
   // update the integer to the quotient
   // cast the remainder as a char
   int count = COUNT;
   while(count > 3)
   {
      int remainder = n % 10;
      n = n / 10;
      result[count] = (char) remainder + 0x30;
      count--;
   }
   while(count == 3)
   {
      result[count] = '.';
      count--;
   }
   while(count == 2)
   {
      int remainder = n % 10;
      n = n / 10;
      result[count] = (char) remainder + 0x30;
      count--;
   }
   while(count >= 0)
   {
      if(n == 0)
      {
         result[count] = ' ';
      }
      else
      {
         int remainder = n % 10;
         n = n / 10;
         result[count] = (char) remainder + 0x30;
      }
      count--;
   }
	 printf("%s\n", result);
   return;
}

/****************Fixed_sDecOut3s***************
 converts fixed point number to ASCII string
 format signed 32-bit with resolution 0.001
 range -9.999 to +9.999
 Input: signed 32-bit integer part of fixed point number
 Output: null-terminated string exactly 6 characters plus null
 Examples
  2345 to " 2.345"  
 -8100 to "-8.100"
  -102 to "-0.102" 
    31 to " 0.031" 
   
 */ 
void Fixed_sDecOut3s(int32_t n)
{
	 char result[6];
	
    // check for valid input
   if(n > 9999 || n < -9999)
   {
      result[5] = '*';
      result[4] = '*';
      result[3] = '*';
      result[2] = '.';
      result[1] = '*';
      result[0] = ' ';

			printf("%s\n", result);
		  return;
   }

   // negative flag
   int neg = 0;
   if(n < 0)
   {
      neg = 1;
      n = n * -1;
   }
   
   // deconstruct integer by dividing by 10
   // update the integer to the quotient
   // cast the remainder as a char
   int count = 5;
   while(count > 2)
   {
      int remainder = n % 10;
      n = n / 10;
      result[count] = (char) remainder + 0x30;
      count--;
   }
   while(count == 2)
   {
      result[count] = '.';
      count--;
   }
   while(count == 1)
   {
      int remainder = n % 10;
      n = n / 10;
      result[count] = (char) remainder + 0x30;
      count--;
   }
   while(count == 0)
   {
      if(neg)
      {
         result[count] = '-';
      }
      else
      {
         result[count] = ' ';
      }
      count--;
   }
	 printf("%s\n", result);
   return;
}

/**************Fixed_uBinOut8***************
 unsigned 32-bit binary fixed-point with a resolution of 1/256. 
 The full-scale range is from 0 to 999.99. 
 If the integer part is larger than 256000, it signifies an error. 
 The Fixed_uBinOut8 function takes an unsigned 32-bit integer part 
 of the binary fixed-point number and outputs the fixed-point value on the OLED. 
 Input: unsigned 32-bit integer part of fixed point number
 Output: none
Parameter LCD display
     0	  0.00
     2	  0.01
    64	  0.25
   100	  0.39
   500	  1.95
   512	  2.00
  5000	 19.53
 30000	117.19
255997	999.99
256000	***.**
*/
void Fixed_uBinOut8(uint32_t n)
{
	 char result[6];
	
    // check for valid input
   if(n >= 256000)
   {
      result[5] = '*';
      result[4] = '*';
      result[3] = '.';
      result[2] = '*';
      result[1] = '*';
      result[0] = '*';
		 
			printf("%s\n", result);
	    return;
   }

   // convert n to a decimal integer
   n = ((n * 100 + 128) / 256);
   
   // deconstruct integer by dividing by 10
   // update the integer to the quotient
   // cast the remainder as a char
   int count = 5;
   while(count > 3)
   {
      int remainder = n % 10;
      n = n / 10;
      result[count] = (char) remainder + 0x30;
      count--;
   }
   while(count == 3)
   {
      result[count] = '.';
      count--;
   }
   while(count == 2)
   {
      int remainder = n % 10;
      n = n / 10;
      result[count] = (char) remainder + 0x30;
      count--;
   }
   while(count >= 0)
   {
      if(n == 0)
      {
         result[count] = ' ';
      }
      else
      {
         int remainder = n % 10;
         n = n / 10;
         result[count] = (char) remainder + 0x30;
      }
      count--;
   }
	 printf("%s\n", result);
   return;
}

