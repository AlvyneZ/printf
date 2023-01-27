#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * init_format_spec - Initializes a given format specifier
 *  array with the supported format specifiers
 * @form_specifiers: format speicier array to be initialized
 */
void init_format_spec(format_spec_t *form_specifiers)
{
	int i;
	format_spec_t f[] = {
		{'c', &print_char},
		{'s', &print_str},
		{'%', &print_pcnt},
		{'d', &print_int},
		{'i', &print_int},
		{'b', &print_bin},
		/*
		 * NOTE: "SUPPORTED_SPEC_COUNT" should be changed in
		 *  main.h after adding new specifiers
		*/
		{0, NULL}
	};

	for (i = 0; i <= SUPPORTED_SPEC_COUNT; i++)
		form_specifiers[i] = f[i];
}

/**
 * check_format - Prints from the given variable list
 *  given the type using a format specifier
 * @specifier: The format specifier
 * @fs: supported format speicier array
 * @var: Pointer to the variable list
 * Return: The number of characters that are printed
 */
int check_format(char specifier, format_spec_t *fs, va_list *var)
{
	unsigned int j, p, c;

	for (c = 0, p = 0, j = 0; (!p) && (fs[j].spec != 0); j++)
	{/* Looping through the supported specifiers */
		if (specifier == fs[j].spec)
		{
			c += fs[j].print_func(var);
			p = 1;
		}
	}
	if (!p)
	{/* Handling when the specifier is not supported */
		c += _putchar('%');
		c += _putchar(specifier);
	}
	return (c);
}

/**
 * _printf - Prints all its parameters (any type) given
 *  a list of types, then followed by a newline
 * @format: list of the types of arguments
 * Return: The number of characters that are printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, c;
	va_list var;
	format_spec_t form[SUPPORTED_SPEC_COUNT + 1];

	init_format_spec(form);
	va_start(var, format);
	for (c = 0, i = 0; ((format != NULL) && (format[i] != '\0')); i++)
	{
		if (format[i] == '%')
		{
			if (format[++i] != '\0')
			{
				c += check_format(format[i], form, &var);
			}
			else
			{/* Handling when '%' is the last character */
				_putchar('%');
				c = -1;
				break;
			}
		}
		else
		{/* Handling a normal character */
			c += _putchar(format[i]);
		}
	}
	va_end(var);
	return (c);
}
