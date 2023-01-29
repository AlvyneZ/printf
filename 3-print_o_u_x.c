#include "main.h"

/**
 * print_oct- Prints an  unsigned int in octal from
 *  the first element of a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_oct(va_list *var, print_buf_t *b)
{
	unsigned int max, zeros, n, cnt;

	zeros = 0;
	cnt = 10;
	n = va_arg(*var, unsigned int);
	for (max = (0x7U << 30); max >= 1; max >>= 3, cnt--)
	{
		if (cnt == 9)
		{
			max = (0x7U << 27);
		}
		if (max == 0x7U)
		{
			zeros = 1;
		}
		if (n & max)
		{
			zeros = 1;
			buf_add_char(('0' + ((n & max) >> (3 * cnt))), b);
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

/**
 * print_ush- Prints an  unsigned short form
 *  the first element of a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_ush(va_list *var, print_buf_t *b)
{
	unsigned int max, zeros, n;

	zeros = 0;
	n = va_arg(*var, unsigned int);
	for (max = 10000; max >= 1; max /= 10)
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

/**
 * print_hex- Prints an  unsigned int in hex (small letters) from
 *  the first element of a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_hex(va_list *var, print_buf_t *b)
{
	unsigned int max, zeros, n, cnt;
	char c;
	zeros = 0;
	cnt = 7;
	n = va_arg(*var, unsigned int);
	for (max = (0xFU << 28); max >= 1; max >>= 4, cnt--)
	{
		if (max == 0xFU)
		{
			zeros = 1;
		}
		if (n & max)
		{
			zeros = 1;
			c = '0' + ((n & max) >> (4 * cnt));
			if (c > 9)
			{
				c += ('a' - ':');
			}
			buf_add_char(c, b);
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


/**
 * print_HeX- Prints an  unsigned int in hex (capital letters) from
 *  the first element of a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_HeX(va_list *var, print_buf_t *b)
{
	unsigned int max, zeros, n, cnt;
	char c;
	zeros = 0;
	cnt = 7;
	n = va_arg(*var, unsigned int);
	for (max = (0xFU << 28); max >= 1; max >>= 4, cnt--)
	{
		if (max == 0xFU)
		{
			zeros = 1;
		}
		if (n & max)
		{
			zeros = 1;
			c = '0' + ((n & max) >> (4 * cnt));
			if (c > 9)
			{
				c += ('A' - ':');
			}
			buf_add_char(c, b);
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
