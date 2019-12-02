#include "ft_printf.h"
#include <math.h>

char*  floatToString(double num, int precision)
{
   int whole_part = num;
   int digit = 0, reminder =0;
   int log_value = log10(num), index = log_value;
   long wt =0;

   // String containg result
   char* str =  ft_memalloc(sizeof(char) * 40);

   //Extract the whole part from float num
   for(int  i = 1 ; i < log_value + 2 ; i++)
   {
       wt  =  pow(10.0,i);
       reminder = whole_part  %  wt;
       digit = (reminder - digit) / (wt/10);

       //Store digit in string
       str[index--] = digit + 48;              // ASCII value of digit  = digit + 48
       if (index == -1)
          break;    
   }

    index = log_value + 1;
    str[index] = '.';

   float fraction_part  = num - whole_part;
   float tmp1 = fraction_part,  tmp =0;

   //Extract the fraction part from  num
   for( int i= 1; i < precision; i++)
   {
      wt =10; 
      tmp  = tmp1 * wt;
      digit = tmp;

      //Store digit in string
      str[++index] = digit +48;           // ASCII value of digit  = digit + 48
      tmp1 = tmp - digit;
   }    

   return str;
}