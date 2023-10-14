#include "main.h"
#include <stddef.h>

/**
 * handle_int - handles integers
 * @n: integer
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: ll
 */

int handle_int(int n, char *buffer, int *tb, int *b)
{
	char *int_str = convert_int(n);
	int len;

	if (int_str == NULL)
		return (-1);
	len = _strlen(int_str);
	if (len >= (BUFFER - *b))
		overflow(buffer, tb, b);
	handle_str(int_str, buffer, tb, b);
	return (0);
}
