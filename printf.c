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
		{'o', &print_oct},
		{'u', &print_ush},
		{'x', &print_hex},
		{'X', &print_HeX},
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
 * @b: A pointer to the print buffer to be used
 */
void check_format(char specifier, format_spec_t *fs,
		va_list *var, print_buf_t *b)
{
	unsigned int j, p;

	for (p = 0, j = 0; (!p) && (fs[j].spec != 0); j++)
	{/* Looping through the supported specifiers */
		if (specifier == fs[j].spec)
		{
			fs[j].print_func(var, b);
			p = 1;
		}
	}
	if (!p)
	{/* Handling when the specifier is not supported */
		buf_add_char('%', b);
		buf_add_char(specifier, b);
	}
}

/**
 * _printf - Prints all its parameters (any type) given
 *  a list of types, then followed by a newline
 * @format: list of the types of arguments
 * Return: The number of characters that are printed
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	va_list var;
	format_spec_t form[SUPPORTED_SPEC_COUNT + 1];
	print_buf_t buf;

	init_format_spec(form);
	buf_init(&buf);
	if (buf.start == NULL)
		return (-1);
	va_start(var, format);
	for (i = 0; ((format != NULL) && (format[i] != '\0')); i++)
	{
		if (format[i] == '%')
		{
			if (format[++i] != '\0')
			{
				check_format(format[i], form, &var, &buf);
			}
			else
			{/* Handling when '%' is the last character */
				buf_add_char('%', &buf);
				buf.prt_cnt = -1;
				break;
			}
		}
		else
		{/* Handling a normal character */
			buf_add_char(format[i], &buf);
		}
	}
	va_end(var);
	buf_write(&buf);
	buf_kill(&buf);
	return (buf.prt_cnt);
}
