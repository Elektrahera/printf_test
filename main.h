#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int _printf(const char *format, ...);
void print_int(int num);

/**
 * FORMAT_SPECIFIER - Format specifier macro for _printf.
 */

#define FORMAT_SPECIFIER() do {\
	switch (*format)\
	{\
		case 'c':\
			putchar(va_arg(args, int));\
			count++;\
			break;\
		case 's':\
			str = va_arg(args, const char *);\
			\
			if (str == NULL)\
			{	\
				write(1, "(null)", 6);\
				count += 6;\
			}	\
			while (*str)\
			{ \
				putchar(*str);\
				str++;\
				count++;\
			} \
			break;\
		case 'd':\
			print_int(va_arg(args, int));\
			count++;\
			break;\
		case 'i':\
			print_int(va_arg(args, int));\
			count++;\
			break;\
		default:\
			putchar('%');\
			putchar(*format);\
			count += 2;\
			break;\
	} \
} while (0)

#endif /* MAIN_H */
