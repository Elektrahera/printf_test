#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
 int i, j;
 int counter = 0; /*variables*/
 char c, *str;
 va_list args;/*argument list*/
 
 va_start(args, format);/*initialize the format string and args variable*/

for (i = 0; format[i]; i++)/*iterate until null terminator*/
{
 if (format[i] == '%')
 {
  i++;
  switch (format[i])
  {
   case 'c':
   {
    c = va_arg(args, int);
    write(1, &c, 1);
    counter++;
    break;
}
case 's':
{
 str = va_arg(args, char *);/*rerive next argument from argument list*/
 for (j = 0; str[j]; j++)
{ 
 write(1, &str[j], 1);
counter++;
}
break;
}
case '%':
{ write(1, "%", 1);/*print the value of % with write function*/
counter++;/*increment value of counter*/
break;
}
default:
break;/*exit current iteration*/
}
else
{
write(1, &format[i], 1);
counter++;
}
}
va_end(args);
return (counter);
  
}
