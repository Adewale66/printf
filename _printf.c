#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - custom printf function
 * @format: format of string
 * Return: int (Number of bytes)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = _strlen(format), i = 0, bytes = 0, total_bytes = 0;
	char *buffer = (char *) malloc(sizeof(char) * BUFFER), fmt;

	if (buffer == NULL)
		return (-1);
	va_start(args, format);
	for (; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			fmt = format[i];
			if (fmt == '%')
				buffer[bytes++] = '%';
			else if (fmt == 'c')
				buffer[bytes++] = va_arg(args, int);
			else if (fmt == 's')
				handle_str(va_arg(args, char *), buffer, &total_bytes, &bytes);
			else if (format[i] == 'i' || format[i] == 'd')
				handle_int(va_arg(args, int), buffer, &total_bytes, &bytes);
		}
		else if (format[i] == '\n')
		{
			overflow(buffer, &total_bytes, &bytes);
			buffer[bytes++] = format[i];
		}
		else
			buffer[bytes++] = format[i];
		if (bytes >= BUFFER)
			overflow(buffer, &total_bytes, &bytes);
	}
	write(1, buffer, bytes);
	free(buffer);
	va_end(args);
	return (total_bytes + bytes);
}
