#include "main.h"
#include <unistd.h>

/**
 * overflow - flushes buffer to stdio
 * @buffer: buffer to check
 * @tb: total bytes to increment
 * @b: number of bytes
 * Return: void
 */

void overflow(char *buffer, int *tb, int *b)
{
	write(1, buffer, *b);
	*tb = *tb + *b;
	*b = 0;
}


