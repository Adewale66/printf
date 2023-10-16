#include "main.h"

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
