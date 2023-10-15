#include "main.h"

/**
 * non_specifier - helper function to handle non specifiers
 * @c: char
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */


int non_specifier(char c, char *buffer, int *tb, int *b)
{
	int error;

	if (c == '\n')
	{
		error = overflow(buffer, tb, b);
		if (error == -1)
			return (-1);
		buffer[*b] = c;
		*b = *b + 1;
	}
	else
	{
		buffer[*b] = c;
		*b = *b + 1;
	}
	if (*b >= BUFFER)
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	return (0);
}
