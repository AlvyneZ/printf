#include "main.h"

/**
 * print_negative - Print a negative multiple digit number
 * @n: Number to print
 * @b: A pointer to the print buffer to be used
 */
void print_negative(int n, print_buf_t *b)
{
	int max, zeros;

	zeros = 0;
	if (n < 0)
	{
		buf_add_char('-', b);
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
					buf_add_char('0', b);
				}
			}
			else
			{
				zeros = 1;
				buf_add_char(('0' + (n / max)), b);
				n %= (-max);
			}
		}
	}
}

/**
 * print_number - Print a multiple digit number including negative sign
 * @n: Number to print
 * @b: A pointer to the print buffer to be used
 */
void print_number(int n, print_buf_t *b)
{
	int max, zeros;

	zeros = 0;
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
					buf_add_char('0', b);
				}
			}
			else
			{
				zeros = 1;
				buf_add_char(('0' + (n / max)), b);
				n %= max;
			}
		}
	}
	else
	{
		print_negative(n, b);
	}
}

/**
 * print_int- Prints an int from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_int(va_list *var, print_buf_t *b)
{
	print_number(va_arg(*var, int), b);
}
