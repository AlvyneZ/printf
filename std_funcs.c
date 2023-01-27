#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _strlen - Gets the length of a string
 * @s: String whose length is required
 * Return: Length of string s
 */
int _strlen(char *s)
{
	int ind;

	for (ind = 0; (*(s + ind) != '\0'); ind++)
	;
	return (ind);
}

/**
 * _puts - writes the strings to stdout
 * @s: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puts(char *s)
{
	return (write(1, s, _strlen(s)));
}

/**
* _memcpy -  Copies n bytes from memory area src to
 *  memory area dest
 * @dest: Destination to paste bytes
 * @src: Source memory area to copy from
 * @n: Maximum bytes of src to be used and bytes to write
 * Return: destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int curs;

	for (curs = 0; curs < n; curs++)
	{
		dest[curs] = src[curs];
	}
	return (dest);
}
