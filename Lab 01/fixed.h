// ************** fixed.h ************** 
// Lab 1 - Fixed point number manipulation
// Omar Marawi, Keith Cyr
// September 3, 2014

/****************Fixed_uDecOut2***************
 outputs the fixed-point value on the display
 format unsigned 32-bit with resolution 0.01
 range 0 to 999.99
 Input: unsigned 32-bit integer part of fixed point number
         greater than 99999 means invalid fixed-point number
 Output: none
 Examples
 12345 to "123.45"  
 22100 to "221.00"
   102 to "  1.02" 
    31 to "  0.31" 
100000 to "***.**"    */ 
void Fixed_uDecOut2(uint32_t n);

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
void Fixed_sDecOut3s(int32_t n);

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
void Fixed_uBinOut8(uint32_t n); 
