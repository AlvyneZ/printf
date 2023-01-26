#include "main.h"

/**
 * print_negative - Print a negative multiple digit number
 * @n: Number to print
 * Return: 1 if number is negative, 0 otherwise
 */
int print_negative(int n)
{
	int max;
	int zeros;

	zeros = 0;
	if (n < 0)
	{
		_putchar('-');
		for (max = -1000000000; max <= -1; max /= 10)
		{
			if (max == -1)
			{
				zeros = 1;
			}
			if (n > max)
			{
				if (zeros)
					_putchar('0');
			}
			else
			{
				zeros = 1;
				_putchar('0' + (n / max));
				n %= (-max);
			}
		}
		return (1);
	}
	return (0);
}

/**
 * print_number - Print a multiple digit number including negative sign
 * @n: Number to print
 */
void print_number(int n)
{
	int max;
	int zeros;

	zeros = 0;
	if (!(print_negative(n)))
	{
		for (max = 1000000000; max >= 1; max /= 10)
		{
			if (max == 1)
			{
				zeros = 1;
			}
			if (n < max)
			{
				if (zeros)
					_putchar('0');
			}
			else
			{
				zeros = 1;
				_putchar('0' + (n / max));
				n %= max;
			}
		}
	}
}

/**
 * print_char- Prints a char from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int print_char(va_list *var)
{
	return (_putchar(va_arg(*var, int)));
}
