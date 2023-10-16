#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * custom_specifier - handles custom specifiers
 * @args: args
 * @c: character
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: bytes
 */

int custom_specifier(va_list args, char c, char *buffer, int *tb, int *b)
{
	int error;

	if (c == 'b')
		error = handle_bin(va_arg(args, int), buffer, tb, b);

	if (error == -1)
		return (-1);
	return (0);
}

/**
 * handle_bin - handle binary
 * @n: int
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */

int handle_bin(unsigned int n, char *buffer, int *tb, int *b)
{
	char *bin;
	int len, error;

	if (n > 4294967294)
		return (-1);

	bin = convert_bin(n);

	if (bin == NULL)
		return (-1);
	len = _strlen(bin);
	if (len >= (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
	{
		free(bin);
		return (-1);
	}
	error = handle_str(bin, buffer, tb, b);
	free(bin);
	if (error == -1)
		return (-1);
	return (0);
}


