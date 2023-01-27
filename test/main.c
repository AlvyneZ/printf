#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    /*unsigned int ui;
    void *addr;*/

    len = _printf("Let's try to printf a simple sentence.%%\n%");
    len2 = printf("Let's try to printf a simple sentence.%%\n%");
    printf("****Length:[%d, %i]\n\n", len, len2);
    /*ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;*/
    len = _printf("Length:[%d, %i]\n", len, len2);
    len2 = printf("Length:[%d, %i]\n", len, len2);
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("Negative:[%d]\n", -762534);
    len2 = printf("Negative:[%d]\n", -762534);
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("Binary:[%b]\n", 4294967295);
    len2 = printf("Binary:[%b]\n", 4294967295);
    printf("****Length:[%d, %i]\n\n", len, len2);
    /*len = _printf("Unsigned:[%u]\n", ui);
    len2 = printf("Unsigned:[%u]\n", ui);
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("Unsigned octal:[%o]\n", ui);
    len2 = printf("Unsigned octal:[%o]\n", ui);
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    len2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("****Length:[%d, %i]\n\n", len, len2);*/
    len = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");
    printf("****Length:[%d, %i]\n\n", len, len2);
    /*len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("****Length:[%d, %i]\n\n", len, len2);
    len = _printf("Unknown:[%r]\n");
    len2 = printf("Unknown:[%r]\n");
    printf("****Length:[%d, %i]\n\n", len, len2);*/
    return (0);
}
