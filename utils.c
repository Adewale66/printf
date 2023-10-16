#include "main.h"
#include <unistd.h>
/**
 * overflow - flushes buffer to stdio
 * @buffer: buffer to check
 * @tb: total bytes to increment
 * @b: number of bytes
 * Return: void
 */

int overflow(char *buffer, int *tb, int *b)
{
	int error;

	error = write(1, buffer, *b);
	if (error == -1)
		return (-1);
	*tb = *tb + *b;
	*b = 0;

	return (0);
}


/**
 * _strlen - returns the length of a string.
 * @s: string parameter
 * Return: int
 */

int _strlen(char *s)
{
	int len;

	if (*s == '\0')
		return (0);
	len = 1 + _strlen(++s);
	return (len);
}

/**
 * reverse - reverses the content of an array of integers.
 * @a: array
 * Return: void
 */

void reverse(char *a)
{
	int i = 0, n = _strlen(a);

	for (; i < n / 2; i++)
	{
		char temp = a[i];

		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
