#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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

int handle_bin(int n, char *buffer, int *tb, int *b)
{
	char *bin;

	if (n < 0 || n > 4294967295)
		return (-1);

	convert_bin(n);
}


