#include "main.h"

/**
 * print_number - Print a number's binary representation
 * @n: Number to print
 * Return: The number of characters that are printed
 */
int print_binary(unsigned int n)
{
	unsigned int max, zeros, c;

	zeros = 0;
	c = 0;
	for (max = (0x1U << 31); max >= 1; max >>= 1)
	{
		if (max == 1)
		{
			zeros = 1;
		}
		if (n & max)
		{
			zeros = 1;
			_putchar('1');
			c++;
		}
		else
		{
			if (zeros)
			{
				_putchar('0');
				c++;
			}
		}
	}
	return (c);
}

/**
 * print_bin- Prints an  unsigned int in binary from
 *  the first element of a given variable list
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int print_bin(va_list *var)
{
	return (print_binary(va_arg(*var, unsigned int)));
}
