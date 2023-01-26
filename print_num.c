#include "main.h"

/**
 * print_num - prints integer to standard output
 * @format: character used to check for null
 * 
 * Return: Nothing
*/
void print_num(char *format, ...) {
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'd':
                    printf("%d", va_arg(args, int));
                    break;
                case 'i':
                    printf("%i", va_arg(args, int));
                    break;
                default:
                    putchar(format[i]);
                    break;
            }
        } else {
            putchar(format[i]);
        }
    }

    va_end(args);
}