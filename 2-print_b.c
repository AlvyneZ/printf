#include "main.h"

/**
 * print_bin- Prints an  unsigned int in binary from
 *  the first element of a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_bin(va_list *var, print_buf_t *b)
{
	unsigned int max, zeros, n;

	zeros = 0;
	n = va_arg(*var, unsigned int);
	for (max = (0x1U << 31); max >= 1; max >>= 1)
	{
		if (max == 1)
		{
			zeros = 1;
		}
		if (n & max)
		{
			zeros = 1;
			buf_add_char('1', b);
		}
		else
		{
			if (zeros)
			{
				buf_add_char('0', b);
			}
		}
	}
}
