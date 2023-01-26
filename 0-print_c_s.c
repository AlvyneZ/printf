#include "main.h"

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
	if (str == NULL)
	{
		return (-1);
	}
	for (c = 0; (*str != '\0'); str++)
	{
		if (_putchar(*str) == 1)
			c++;
		else
			return (-1);
	}
	return (c);
}

/**
 * print_pcnt- Prints a percentage sign
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int print_pcnt(va_list *var)
{
	(void)var;
	return (_putchar('%'));
}
