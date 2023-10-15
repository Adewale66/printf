#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - custom printf function
 * @format: format of string
 * Return: int (Number of bytes)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = _strlen(format), i = 0, bytes = 0, total_bytes = 0, error;
	char *buffer = (char *) malloc(sizeof(char) * BUFFER);

	if (buffer == NULL)
		return (-1);
	va_start(args, format);
	for (; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				buffer[bytes++] = '%';
			else if (format[i] == 'c')
				buffer[bytes++] = va_arg(args, int);
			else if (format[i] == 's')
				error = handle_str(va_arg(args, char *), buffer, &total_bytes, &bytes);
			else if (format[i] == 'i' || format[i] == 'd')
				error = handle_int(va_arg(args, int), buffer, &total_bytes, &bytes);
		}
		else
			error = non_specifier(format[i], buffer, &total_bytes, &bytes);
		if (error == -1)
		{
			free(buffer);
			va_end(args);
			return (-1);
		}
	}
	error = write(1, buffer, bytes);
	free(buffer);
	va_end(args);
	return (total_bytes + bytes);
}
