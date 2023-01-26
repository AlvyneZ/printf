#ifndef _MAIN_H_
#define _MAIN_H_

#define SUPPORTED_SPEC_COUNT 3
#define NULL ((void *)0)

#include <stdarg.h>

typedef int (*print_func_t)(va_list *);

/**
 * struct format_spec_s - Format specifier details
 * @spec: Type Specifier character
 * @print_func: Function to print the given type
 */
typedef struct format_spec_s
{
	char spec;
	print_func_t print_func;
} format_spec_t;

int _putchar(char c);
int _strlen(char *s);
int _puts(char *s);

int _printf(const char *format, ...);

int print_char(va_list *var);
int print_str(va_list *var);
int print_pcnt(va_list *var);

void my_printf(const char *format, ...);

#endif /* _MAIN_H_ */
