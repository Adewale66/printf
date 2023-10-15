#include <stdarg.h>
#include "main.h"

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
		buffer[*b] = va_arg(args, int);
		*b = *b + 1;
	}
	else if (c == 's')
		error = handle_str(va_arg(args, char *), buffer, tb, b);
	else if (c == 'i' || c == 'd')
		error = handle_int(va_arg(args, int), buffer, tb, b);

	if (*b >= BUFFER && error != -1)
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	return (0);
}
