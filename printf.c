#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - custom printf function
 * @ft: format of string
 * Return: int (Number of bytes)
 */

int _printf(const char *ft, ...)
{
	va_list args;
	int bytes = 0, total_bytes = 0, error = 0;
	char buffer[BUFFER];

	if (ft == NULL)
		return (-1);
	va_start(args, ft);
	while (*ft != '\0')
	{
		if (*ft == '%')
		{
			++ft;
			if (*ft == '%')
				buffer[bytes++] = *ft;
			else if (*ft == 'c' || *ft == 's' || *ft == 'i' || *ft == 'd' || *ft == 'p')
				error = non_custom_specifier(args, *ft, buffer, &total_bytes, &bytes);
			else if (*ft == 'b' || *ft == 'R' || *ft == 'S' || *ft == 'r')
				error = custom_specifier(args, *ft, buffer, &total_bytes, &bytes);
			else if (*ft == '0' || *ft == '-' || *ft == '+' || *ft == '#' || *ft == ' ')
				error = 0;
			else if (*ft == 'l' || *ft == 'h')
				error = 0;
			else if (*ft == 'u' || *ft == 'o' || *ft == 'x' || *ft == 'X')
				error = non_custom_specifier(args, *ft, buffer, &total_bytes, &bytes);
			else
				error = handle_unknown(*ft, buffer, &total_bytes, &bytes);
		}
		else
			error = non_specifier(*ft, buffer, &total_bytes, &bytes);
		if (error == -1)
			return (exit_error(args));
		ft++;
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

	va_end(args);
	if (error == -1)
		return (-1);
	return (tb + b);
}

/**
 * exit_error - exits the program
 * @args: args
 * Return: int
 */

int exit_error(va_list args)
{
	va_end(args);
	return (-1);
}

/**
 * handle_unknown - helper function for unknown specifiers
 * @c: spec
 * @buffer: buffer
 * @total_bytes: total_bytes
 * @bytes: bytes
 * Return: int
 */

int handle_unknown(char c, char *buffer, int *total_bytes, int *bytes)
{
	int error = 0;

	if (*bytes + 2 > BUFFER)
		error = overflow(buffer, total_bytes, bytes);
	if (error != -1)
	{
		if (c < 33 || c > 126)
			return (-1);
		buffer[(*bytes)++] = '%';
		buffer[(*bytes)++] = c;
		return (0);
	}
	return (-1);
}

/**
 * non_specifier - helper function to handle non specifiers
 * @c: char
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */

int non_specifier(char c, char *buffer, int *tb, int *b)
{
	int error = 0;

	if (c == '\n')
	{
		error = overflow(buffer, tb, b);
		if (error == -1)
			return (-1);
		buffer[*b] = c;
		*b = *b + 1;
	}
	else
	{
		buffer[*b] = c;
		*b = *b + 1;
	}
	if (*b >= BUFFER)
		error = overflow(buffer, tb, b);
	if (error == -1)
		return (-1);
	return (0);
}
