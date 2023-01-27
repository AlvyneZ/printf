#ifndef _MAIN_H_
#define _MAIN_H_

#define SUPPORTED_SPEC_COUNT 6
#define PRINTF_BUF_SIZE 1024
#define NULL ((void *)0)

#include <stdarg.h>

/**
 * struct print_buf_s - printf buffer details
 * @start: Pointer to the beginning of the buffer
 * @curs: Pointer to where the next character should be placed
 * @end: Pointer to the end of the buffer (should not be written to)
 * @prt_cnt: Number of characters that have been printed from buffer
 */
typedef struct print_buf_s
{
	char *start;
	char *curs;
	char *end;
	int prt_cnt;
} print_buf_t;

/* 4-print_buf.c functions */
void buf_init(print_buf_t *b);
void buf_kill(print_buf_t *b);
void buf_add_char(char c, print_buf_t *b);
void buf_add_str(char *s, print_buf_t *b);
int buf_write(print_buf_t *b);

typedef void (*print_func_t)(va_list *, print_buf_t *);

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
char *_memcpy(char *dest, char *src, unsigned int n);

/* printf.c functions */
int _printf(const char *format, ...);

/* Main printing functions for each data type */
/* 0-print_c_s.c */
void print_char(va_list *var, print_buf_t *b);
void print_str(va_list *var, print_buf_t *b);
void print_pcnt(va_list *var, print_buf_t *b);
/* 1-print_d_i.c */
void print_int(va_list *var, print_buf_t *b);
/* 2-print_b.c */
void print_bin(va_list *var, print_buf_t *b);

#endif /* _MAIN_H_ */
