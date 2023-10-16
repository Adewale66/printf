#include <stdlib.h>
#include "main.h"
#include <stdio.h>


/**
 * convert_bin - converts int to binary
 */

void convert_bin(int num)
{
	int i = 0, j = 0;
	char *c = (char *) malloc (sizeof(char) * 32);

	if (c == NULL)
		return;
	while (num != 0)
	{
		if (num % 2 == 0)
			c[i] = '0';
		else
			c[i] = '1';
		i++;
		num /= 2;
	}
	char *n = (char *) malloc (sizeof(char) * (i + 1));

	if (n == NULL)
		return;

	while (j != i)
	{
		n[j] = c[j];
		j++;
	}
	n[j] = '\0';
	free(c);
	reverse(n, j);

	printf("%s\n", n);
}
