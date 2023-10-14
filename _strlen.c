#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: string parameter
 * Return: int
 */

int _strlen(const char *s)
{
	int len;

	if (*s == '\0')
		return (0);
	len = 1 + _strlen(++s);
	return (len);
}
