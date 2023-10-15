#ifndef __PRINTF__
#define __PRINTF__
#define BUFFER 1024

int _strlen(const char *);
int _printf(const char *, ...);
int overflow(char *, int *, int *);
int handle_str(char *, char *, int *, int *);
int handle_int(int, char *, int *, int *);
char *convert_int(int);
int non_specifier(char, char *, int *, int *);

#endif
