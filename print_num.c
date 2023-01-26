#include "main.h"

/**
 * print_num - prints integer to standard output
 * @format: character used to check for null
 * 
 * Return: Nothing
*/

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) 
    {
        if (format[i] == '%') 
        {
            i++;
            switch (format[i]) 
            {
                case 'd':
                case 'i':
                {
                    int value = va_arg(args, int);
                    char buffer[12];
                    char *p = buffer + sizeof(buffer);
                    unsigned v;
                    if (value < 0) 
                    {
                        v = -value;
                        *--p = '-';
                    }
                    else 
                    {
                        v = value;
                    }
                    do
                    {
                        *--p = v % 10 + '0';
                        v /= 10;
                    }
                    while (v);
                    fwrite(p, 1, buffer + sizeof(buffer) - p, stdout);
                    break;
                }
                default:
                    putchar(format[i]);
                    break;
            }
        }
        else 
        {
            putchar(format[i]);
        }
    }
    va_end(args);
}