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
		/*
		 * NOTE: "SUPPORTED_SPEC_COUNT" should be changed in
		 *  main.h after adding new specifiers
		 * {'i', &print_int},
		 * {'f', &print_float}
		*/
		{0, NULL}
	};

	for (i = 0; i < SUPPORTED_SPEC_COUNT; i++)
		form_specifiers[i] = f[i];
}

/**
 * _printf - Prints all its parameters (any type) given
 *  a list of types, then followed by a newline
 * @format: list of the types of arguments
 * Return: The number of characters that are printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, j, p, c;
	va_list var;
	format_spec_t form[SUPPORTED_SPEC_COUNT];

	init_format_spec(form);
	va_start(var, format);
	for (c = 0, i = 0; ((format != NULL) && (format[i] != '\0')); i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
			{
				for (p = 1, j = 0; (p) && (form[j].spec != 0); j++)
				{/* Looping through the supported specifiers */
					if (format[i] == form[j].spec)
					{
						c += form[j].print_func(&var);
						p = 0;
					}
				}
				if (p)
				{/* Handling when the specifier is not supported */
					c += _putchar('%');
					c += _putchar(format[i]);
				}
			}
			else
			{/* Handling when '%' is the last character */
				c += _putchar('%');
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
