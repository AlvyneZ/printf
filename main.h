#ifndef _MAIN_H_
#define _MAIN_H_

#define SUPPORTED_SPEC_COUNT 6
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

/* std_funcs.c functions */
int _putchar(char c);
int _strlen(char *s);
int _puts(char *s);

/* printf.c functions */
int _printf(const char *format, ...);

/* Main printing functions for each data type */
/* 0-print_c_s.c */
int print_char(va_list *var);
int print_str(va_list *var);
int print_pcnt(va_list *var);
/* 1-print_d_i.c */
int print_int(va_list *var);
/* 2-print_b.c */
int print_bin(va_list *var);

#endif /* _MAIN_H_ */
