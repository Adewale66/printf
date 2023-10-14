#include "main.h"

/**
 * handle_str - handles string modifier
 * @string: string parameter
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: void
 */


void handle_str(char *string, char *buffer, int *tb, int *b)
{
	int s_len = _strlen(string);

	if (s_len >= (BUFFER - *b))
		overflow(buffer, tb, b);
	while (*string != '\0')
	{
		buffer[*b] = *string;
		*b = *b + 1;
		string++;
	}
}
