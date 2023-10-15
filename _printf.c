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
	}
	return (exit_program(args, buffer, total_bytes, bytes));
}

/**
 * exit_program - exits the program
 * @args: args
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */


int exit_program(va_list args, char *buffer, int tb, int b)
{
	int error = write(1, buffer, b);

	free(buffer);
	va_end(args);
	if (error == -1)
		return (-1);
	return (tb + b);
}
