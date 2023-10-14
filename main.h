#ifndef __PRINTF__
#define __PRINTF__
#define BUFFER 1024

int _strlen(const char *);
int _printf(const char *, ...);
void overflow(char *, int *, int *);
void handle_str(char *, char *, int *, int *);
int handle_int(int , char *, int *, int *);
char *convert_int(int);

#endif
