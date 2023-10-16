#include "main.h"
#include <stdlib.h>


/**
 * decToHexa - converts dev to hex
 * @n: int
 * @buffer: buffer
 * @b: bytes
 * Return: char *
 */

int decToHexa(int n, char *buffer, int *b)
{
	char hexBuffer[9], ch, *res;
	int index = 0, i, j, rem = 0;

	while (n != 0)
	{
		rem = n % 16;
		if (rem < 10)
			ch = rem + '0';
		else
			ch = rem + 'A' - 10;
		hexBuffer[index++] = ch;
		n = n / 16;
	}
	hexBuffer[index] = '\0';
	i = 0;
	j = index - 1;
	while (i <= j)
	{
		char temp = hexBuffer[i];

		hexBuffer[i] = hexBuffer[j];
		hexBuffer[j] = temp;
		i++;
		j--;
	}

	res = (char *) malloc(_strlen(hexBuffer) + 1);

	if (res != NULL)
		_strcpy(res, hexBuffer);

	buffer[(*b)++] = 92;
	buffer[(*b)++] = 'x';
	if (_strlen(res) == 1)
		buffer[(*b)++] = '0';
	buffer[(*b)++] = res[0];
	buffer[(*b)++] = res[1];
	free(res);
	return (0);
}

