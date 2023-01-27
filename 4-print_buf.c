#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * buf_init - initializes memory for a printf buffer
 * @b: The buffer to be initialized
 */
void buf_init(print_buf_t *b)
{
	b->start = malloc(PRINTF_BUFFER_SIZE);
	b->curs = b->start;
	b->end = b->start + PRINTF_BUFFER_SIZE;
	b->prt_cnt = 0;
}

/**
 * buf_kill - frees up memory for a printf buffer
 * @b: The buffer to be deinitialized
 */
void buf_kill(print_buf_t *b)
{
	free(b->start);
}

/**
 * buf_add_char - writes the character c to print buffer
 *  and prints the entire buffer to stdout if it is full
 * @c: The character to print
 * @b: A pointer to the print buffer
 */
void buf_add_char(char c, print_buf_t *b)
{
	if (b->curs == b->end)
	{
		buf_write(b);
	}
	*(b->curs) = c;
	b->curs++;
}

/**
 * buf_add_str - writes the string s to print buffer
 *  and prints the entire buffer to stdout if it is full
 * @s: The string to print
 * @b: A pointer to the print buffer
 */
void buf_add_str(char *s, print_buf_t *b)
{
	int slen, blen;

	slen = _strlen(s);
	blen = b->end - b->curs;
	if (slen > blen)
	{
		_memcpy(b->curs, s, (slen - blen));
		b->curs = b->end;
		buf_write(b);
		s = &(s[blen]);
		slen -= blen;
	}
	_memcpy(b->curs, s, slen);
	b->curs += slen;
}

/**
 * buf_write - prints the entire buffer to stdout
 * @b: A pointer to the print buffer
 * Return: The number of characters printed in this
 *  write call
 */
int buf_write(print_buf_t *b)
{
	int cnt;

	cnt = b->curs - b->start;
	if (cnt)
	{
		b->curs = b->start;
		cnt = write(1, b->start, cnt);
		if (cnt == -1)
			b->prt_cnt = -1;
	}
	if (b->prt_cnt != -1)
		b->prt_cnt += cnt;
	return (cnt);
}
