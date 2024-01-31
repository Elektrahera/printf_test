#include "main.h"
#include <math.h>

/**
 * print_int - Functyion that prints ints.
 * @num: Int parameter to print.
 * Return: void.
 */

void print_int(int num)
{
	int i = 0;
	char num_digits[20];

	if (num < 0)
	{
		putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		putchar('0');
		return;
	}
	while (num > 0)
	{
		num_digits[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (--i >= 0)
	{
		putchar(num_digits[i]);
	}
}
