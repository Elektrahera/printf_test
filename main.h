#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <strings.h>

/**
 * struct fmt - function to check for formats
 * @type: The format to print
 * @f: The print function to use
 */
typedef struct fmt
{
	char *type;
	int (*f)();
} fmt_t;

int _printf(const char *format, ...);

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
			while (*str)\
			{ \
				putchar(*str++);\
				count++;\
			} \
			break;\
		case '%':\
			putchar('%');\
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
