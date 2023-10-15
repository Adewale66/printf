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
