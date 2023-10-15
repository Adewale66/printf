#include "main.h"
#include <stddef.h>
#include <stdlib.h>

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
	int len, error;

	if (int_str == NULL)
		return (-1);
	len = _strlen(int_str);
	if (len >= (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
	{
		free(int_str);
		return (-1);
	}
	handle_str(int_str, buffer, tb, b);
	free(int_str);
	return (0);
}
