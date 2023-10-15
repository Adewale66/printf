#include "main.h"
#include <unistd.h>

/**
 * overflow - flushes buffer to stdio
 * @buffer: buffer to check
 * @tb: total bytes to increment
 * @b: number of bytes
 * Return: void
 */

int overflow(char *buffer, int *tb, int *b)
{
	int error;

	error = write(1, buffer, *b);
	if (error == -1)
		return (-1);
	*tb = *tb + *b;
	*b = 0;

	return (0);
}


