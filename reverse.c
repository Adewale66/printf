#include "main.h"

/**
 * reverse - reverses the content of an array of integers.
 * @a: array
 * @n: length of array
 * Return: void
 */

void reverse(char *a, int n)
{
	int i = 0;

	for (; i < n / 2; i++)
	{
		char temp = a[i];

		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
