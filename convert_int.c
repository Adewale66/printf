#include "main.h"
#include <stdlib.h>

/**
 * convert_int - helper function to convert int to string
 * @n: number to convert
 * Return: char pointer (string)
 */

char *convert_int(int n)
{
	int length = 0, temp = n, i;
	char *str;

	while (temp != 0)
	{
		temp /= 10;
		length++;
	}
	if (length == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = length - 1;
	while (n != 0)
	{
		str[i] = (char)((n % 10) + '0');
		n /= 10;
		i--;
	}
	str[length] = '\0';
	return (str);
}
