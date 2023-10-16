#include <stdlib.h>
#include "main.h"

/**
 * convert_bin - converts int to binary
 * @num: int
 * Return: char *
 */

char *convert_bin(unsigned int num)
{
	int i = 0, j = 0;
	char *c = (char *) malloc(sizeof(char) * 32), *n;

	if (c == NULL)
		return (NULL);
	if (num == 0)
	{
		i = 1;
		c[0] = '0';
	}
	else
	{

		while (num != 0)
		{
			if (num % 2 == 0)
				c[i] = '0';
			else
				c[i] = '1';
			i++;
			num /= 2;
		}
	}

	n = (char *) malloc(sizeof(char) * (i + 1));
	if (n == NULL)
		return (NULL);
	while (j != i)
	{
		n[j] = c[j];
		j++;
	}
	n[j] = '\0';
	free(c);
	reverse(n);

	return (n);
}
