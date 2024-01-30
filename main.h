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
 * FORMAT_SPECIFIER - Macro to handle format specifiers through switch cases.
 */

#define FORMAT_SPECIFIER() do { \
	switch (*format) \
	{ \
	case 'c': \
		putchar(va_arg(args, int)); \
		count++; \
		break; \
	case 's': \
		str = va_arg(args, const char *); \
		while (*str) \
		{ \
			putchar(*str++); \
			count++; \
		} \
		break; \
	case '%': \
		putchar('%'); \
		count++; \
		break; \
	case 'd': \
		print_int(va_arg(args, int)); \
		count++; \
		break; \
	case 'i': \
		print_int(va_arg(args, int)); \
		count++;  \
		break; \
	case 'b': \
		print_binary(va_arg(args, uint64_t)); \
		count++; \
		break; \
	default: \
		putchar('%'); \
		putchar(*format); \
		count += 2; \
		break; \
	} \
} while (0)

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
int print_op(const char *format, fmt_t *print_arr, va_list list);
int ch(va_list character);
int str(va_list string);
int _int(va_list integ);
int _ui(va_list unsign);
int _oct(va_list octo);
int _rot13(va_list rot);
int _hex_str(unsigned int n, unsigned int hex, char alpha);
int _hex_l(va_list hexa);
int _hex_u(va_list hexa);
int _strlen(char *s);
int _bin(va_list bin);
int _putchar(char c);

#endif /* MAIN_H */
