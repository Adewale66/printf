#ifndef __PRINTF__
#define __PRINTF__
#define BUFFER 1024
#include <stdarg.h>

int _strlen(char *);
int _printf(const char *, ...);
int overflow(char *, int *, int *);
int handle_str(char *, char *, int *, int *);
int handle_int(int, char *, int *, int *);
int handle_bin(unsigned long int, char *, int *, int *);
char *convert_int(int);
char *convert_unsigned_int(unsigned long int);
char *convert(unsigned long int, int);
char *convert_oct (unsigned int);
int non_specifier(char, char *, int *, int *);
int non_custom_specifier(va_list, char, char *, int *, int *);
int handle_unknown(char, char *, int *, int *);
int custom_specifier(va_list, char, char *, int *, int *);
int exit_program(va_list, char *, int, int);
int exit_error(va_list);
void reverse(char *);
int rot13(char *, char *, int *, int *);
char *_strcpy(char *, char *);
int handle_non_printable(char *, char *, int *, int *);
int decToHexa(int, char *, int *);
int unsigned_int(unsigned long int, char *, int *, int *, char);
int convert_toHex(unsigned long int, char, char *, int *, int *);

#endif
