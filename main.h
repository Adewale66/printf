#ifndef __PRINTF__
#define __PRINTF__
#define BUFFER 1024
#include <stdarg.h>

int _strlen(const char *);
int _printf(const char *, ...);
int overflow(char *, int *, int *);
int handle_str(char *, char *, int *, int *);
int handle_int(int, char *, int *, int *);
char *convert_int(int);
int non_specifier(char, char *, int *, int *);
int non_custom_specifier(va_list, char, char *, int *, int *);
int exit_program(va_list, char *, int, int);


#endif
