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
	else if (c == 'R')
	{
		char *c = va_arg(args, char *);

		error = rot13(c, buffer, tb, b);
		if (error == -1)
			return (-1);
	}
	else if (c == 'r')
	{
		char *c = va_arg(args, char *);
		char *t = (char *) malloc (sizeof(char) * (_strlen(c) + 1));
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
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: int
 */

int rot13(char *s, char *buffer, int *tb, int *b)
{
	int i, j, error;
	char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot_val[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (_strlen(s) > (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
		for (j = 0; j < 52; j++)
			if (s[i] == characters[j])
			{
				buffer[(*b)++] = rot_val[j];
				break;
			}
	return (0);
}



/**
 * _strcpy -  copies the string pointed to by src
 * @dest : destination parameter
 * @src: source parameter
 * Return: pointer
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0, i = 0;

	while (src[len] != '\0')
		len++;

	for (; i <= len; i++)
		dest[i] = src[i];
	return (dest);
}
