#include "main.h"

/**
 * print_char- Prints a char from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_char(va_list *var, print_buf_t *b)
{
	buf_add_char((va_arg(*var, int)), b);
}

/**
 * print_str- Prints a string from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_str(va_list *var, print_buf_t *b)
{
	char *str;

	str = va_arg(*var, char *);
	if (str != NULL)
	{
		buf_add_str(str, b);
	}
}

/**
 * print_pcnt- Prints a percentage sign
 * @var: Pointer to the variable list
 * @b: A pointer to the print buffer to be used
 */
void print_pcnt(va_list *var, print_buf_t *b)
{
	(void)var;
	buf_add_char('%', b);
}
