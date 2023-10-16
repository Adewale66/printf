#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * non_custom_specifier -helper function to handle no specifier
 * @args: arguments
 * @c: character
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */

int non_custom_specifier(va_list args, char c, char *buffer, int *tb, int *b)
{
	int error;

	if (c == 'c')
	{
		int t = va_arg(args, int);

		if (c == '\0')
			return (-1);
		buffer[(*b)++] = t;
	}
	else if (c == 's')
		error = handle_str(va_arg(args, char*), buffer, tb, b);
	else if (c == 'i' || c == 'd')
		error = handle_int(va_arg(args, int), buffer, tb, b);
	else if (c == 'u')
		error = handle_unsigned_int(va_arg(args, unsigned int), buffer, tb, b, c);
	else if (c == 'o')
		error = handle_unsigned_int(va_arg(args, unsigned int), buffer, tb, b, c);
	if (*b > BUFFER && error != -1)
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	return (0);
}


/**
 * handle_int - handles integers
 * @n: integer
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: int
 */

int handle_int(int n, char *buffer, int *tb, int *b)
{
	char *int_str = convert_int(n);
	int len, error;

	if (int_str == NULL)
		return (-1);
	len = _strlen(int_str);
	if (len > (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
	{
		free(int_str);
		return (-1);
	}
	error = handle_str(int_str, buffer, tb, b);
	free(int_str);
	if (error == -1)
		return (-1);
	return (0);
}


/**
 * handle_str - handles string modifier
 * @s: string parameter
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: void
 */


int handle_str(char *s, char *buffer, int *tb, int *b)
{
	int s_len = _strlen(s), error;

	if (s == NULL)
		return (-1);

	if (s_len > (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	while (*s != '\0')
	{
		buffer[(*b)++] = *s;
		s++;
	}
	return (0);
}
/**
 * handle_unsigned_int - handles integers
 * @n: integer
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * @t: type
 * Return: void
 */

int handle_unsigned_int(unsigned int n, char *buffer, int *tb, int *b, char t)
{
	char *int_str = t == 'o' ? convert_oct(n) : convert_unsigned_int(n);
	int len, error;

	if (int_str == NULL)
		return (-1);
	len = _strlen(int_str);
	if (len > (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
	{
		free(int_str);
		return (-1);
	}
	error = handle_str(int_str, buffer, tb, b);
	free(int_str);
	if (error == -1)
		return (-1);
	return (0);
}
