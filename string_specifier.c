#include "main.h"

/**
 * handle_str - handles string modifier
 * @string: string parameter
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: void
 */


int handle_str(char *string, char *buffer, int *tb, int *b)
{
	int s_len = _strlen(string), error;

	if (s_len >= (BUFFER - *b))
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	while (*string != '\0')
	{
		buffer[*b] = *string;
		*b = *b + 1;
		string++;
	}
	return (0);
}
