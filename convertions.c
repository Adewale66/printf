#include "main.h"
#include <stdlib.h>

/**
 * convert_int - helper function to convert int to string
 * @num: number to convert
 * Return: char pointer (string)
 */

char *convert_int(int num)
{
	int isNegative = 0, length, i, temp;
	char *str;

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}

	length = isNegative ? 2 : 1;

	temp = num;
	while (temp /= 10)
		length++;

	str = (char *) malloc(length + 1);

	if (str == NULL)
		return (NULL);

	i = length - 1;
	str[i + 1] = '\0';


	do {
		str[i--] = num % 10 + '0';
		num /= 10;
	} while (num > 0);


	if (isNegative)
		str[0] = '-';

	return (str);
}

/**
 * convert_unsigned_int - helper function to convert int to string
 * @num: number to convert
 * Return: char pointer (string)
 */

char *convert_unsigned_int(unsigned int num)
{
	int length, i, temp;
	char *str;

	length = 1;

	temp = num;
	while (temp /= 10)
		length++;

	str = (char *) malloc(length + 1);

	if (str == NULL)
		return (NULL);

	i = length - 1;
	str[i + 1] = '\0';


	do {
		str[i--] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	return (str);
}

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
	if (_strlen(res) < 2)
		buffer[(*b)++] = '0';
	buffer[(*b)++] = res[0];
	if (_strlen(res) > 1)
		buffer[(*b)++] = res[1];
	free(res);
	return (0);
}

