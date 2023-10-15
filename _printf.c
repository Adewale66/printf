#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - custom printf function
 * @format: format of string
 * Return: int (Number of bytes)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = _strlen(format), i = 0, bytes = 0, total_bytes = 0, error;
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
				buffer[bytes++] = fmt;
			else if (fmt == 'c' || fmt == 's' || fmt == 'i' || fmt == 'd' || fmt == 'p')
				error = non_custom_specifier(args, fmt, buffer, &total_bytes, &bytes);
			else
			{
				if (bytes + 2 >= BUFFER)
					error = overflow(buffer, &total_bytes, &bytes);
				if (error != -1)
				{
					buffer[bytes++] = '%';
					buffer[bytes++] = fmt;
				}
			}
		} else
			error = non_specifier(format[i], buffer, &total_bytes, &bytes);
		if (error == -1)
		{
			free(buffer);
			va_end(args);
			return (-1);
		}
	} error = write(1, buffer, bytes);
	free(buffer);
	va_end(args);
	return (total_bytes + bytes);
}
