#include "main.h"
#include <stdio.h>
#include <limits.h>

void decToHex(unsigned long int n);

int main(void)
{

	int len;
	int len2;
	unsigned int ui;

	ui = (unsigned int) INT_MAX + 1024;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("%R\n", "hellozebraomo");
	_printf("%r\n", "hello");
	_printf("%S\n", "Best\nSchool");
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	len = printf("%%%s\n", "hello");
	len2 = _printf("%%%s\n", "hello");
	printf("%d, %d\n", len, len2);
	_printf("Unsigned octal:[%o]\n", ui);
	_printf("binary:[%b]\n", 98);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("backslash test \\\n");
	_printf("backslash test \\\n");
	printf("%5d\n", 123);
	return (0);
}
void decToHex(unsigned long int n)
{
	char hexBuffer[9], ch, temp;
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
		temp = hexBuffer[i];
		hexBuffer[i] = hexBuffer[j];
		hexBuffer[j] = temp;
		i++;
		j--;
	}
	printf("hes: %s\n", hexBuffer);
}

