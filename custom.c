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
		error = handle_bin(va_arg(args, unsigned int), buffer, tb, b);
	else if (c == 'r')
	{
		char *c = va_arg(args, char *);
		reverse(c);
	}
	else if (c == 'R')
		error = handle_str(rot13(va_arg(args, char *)), buffer, tb, b);

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

/**
 * rot13 - encodes a string using rot13.
 * @s: string parameter
 * Return: char *
 */

char *rot13(char *s)
{
	int i, j;
	char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot_val[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; s[i] != '\0'; i++)
		for (j = 0; j < 52; j++)
			if (s[i] == characters[j])
			{
				s[i] = rot_val[j];
				break;
			}
	return (s);
}
