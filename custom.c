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
	int error = 0;

	if (c == 'b')
		error = handle_bin(va_arg(args, unsigned long), buffer, tb, b);
	else if (c == 'R')
		error = rot13(va_arg(args, char *), buffer, tb, b);
	else if (c == 'S')
	{
		char *s = va_arg(args, char*);

		if (s == NULL)
			return (-1);
		error = handle_non_printable(s, buffer, tb, b);
	}
	else if (c == 'r')
	{
		char *c = va_arg(args, char *);
		char *t = (char *) malloc(sizeof(char) * (_strlen(c) + 1));

		if (t == NULL)
			return (-1);
		_strcpy(t, c);
		reverse(t);
		error = handle_str(t, buffer, tb, b);
		free(t);
	}
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

int handle_bin(unsigned long n, char *buffer, int *tb, int *b)
{
	char *bin;
	int len, error = 0;

	bin = convert(n, 2);

	if (bin == NULL)
		return (-1);
	len = _strlen(bin);
	if (len > (BUFFER - *b))
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


/**
 * handle_non_printable - hanldes non printable
 * @s: string
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */

int handle_non_printable(char *s, char *buffer, int *tb, int *b)
{
	int error = 0;

	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		if (*s < 32 || *s > 126)
		{
			if (*b + 4 > BUFFER)
				error = overflow(buffer, tb, b);
			if (error != -1)
			{
				error = decToHexa(*s, buffer, b);
				if (error == -1)
					return (-1);
			}
			else
				return (-1);
		}
		else
		{
			if (*b + 1 > BUFFER)
				error = overflow(buffer, tb, b);
			if (error != -1)
				buffer[(*b)++] = *s;
			else
				return (-1);
		}
		s++;
	}
	return (0);
}
