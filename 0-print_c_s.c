#include "main.h"

/**
 * print_char- Prints a char from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int print_char(va_list *var)
{
	return ((_putchar(va_arg(*var, int)) == 1) ? 1 : 0);
}

/**
 * print_str- Prints a string from the first element of
 *  a given variable list
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int print_str(va_list *var)
{
	int c;
	char *str;

	str = va_arg(*var, char *);
	if (str != NULL)
	{
		for (c = 0; (*str != '\0'); str++)
		{
			c += ((_putchar(*str) == 1) ? 1 : 0);
		}
	}
	return (c);
}
