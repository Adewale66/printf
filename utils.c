#include "main.h"
#include <unistd.h>

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

	if (s == NULL)
		return (-1);

	if (_strlen(s) > BUFFER)
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


/**
 * _strlen - returns the length of a string.
 * @s: string parameter
 * Return: int
 */

int _strlen(char *s)
{
	int len;

	if (*s == '\0')
		return (0);
	len = 1 + _strlen(++s);
	return (len);
}

/**
 * reverse - reverses the content of an array of integers.
 * @a: array
 * Return: void
 */

void reverse(char *a)
{
	int i = 0, n = _strlen(a);

	for (; i < n / 2; i++)
	{
		char temp = a[i];

		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
