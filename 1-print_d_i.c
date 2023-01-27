#include "main.h"

/**
 * print_negative - Print a negative multiple digit number
 * @n: Number to print
 * Return: The number of characters that are printed
 */
int print_negative(int n)
{
	int max, zeros, c;

	zeros = 0;
	c = 0;
	if (n < 0)
	{
		_putchar('-');
		c++;
		for (max = -1000000000; max <= -1; max /= 10)
		{
			if (max == -1)
			{
				zeros = 1;
			}
			if (n > max)
			{
				if (zeros)
				{
					_putchar('0');
					c++;
				}
			}
			else
			{
				zeros = 1;
				_putchar('0' + (n / max));
				c++;
				n %= (-max);
			}
		}
		return (c);
	}
	return (0);
}

/**
 * print_number - Print a multiple digit number including negative sign
 * @n: Number to print
 * Return: The number of characters that are printed
 */
int print_number(int n)
{
	int max, zeros, c;

	zeros = 0;
	c = 0;
	if (n >= 0)
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
				{
					_putchar('0');
					c++;
				}
			}
			else
			{
				zeros = 1;
				_putchar('0' + (n / max));
				n %= max;
				c++;
			}
		}
		return (c);
	}
	else
	{
		return (print_negative(n));
	}
}

/**
 * print_int- Prints an int from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int print_int(va_list *var)
{
	return (print_number(va_arg(*var, int)));
}
