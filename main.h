#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - Structure for printer functions
 * @type_arg: Identifier for the type
 * @f: Pointer to a printer function
 *
 * Description: This structure stores pointers to printer functions.
 */
typedef struct print
{
    char *type_arg;
    int (*f)(va_list, char *, unsigned int);
} print_t;

int _putchar(char c)
int _printf(const char *format, ...);
int printf_char(val_list val)
int printf_char(val_list val)	
int printf_string(val_list val)
int _strlen(char *str)
int _strlenc(const char *str)
int print_percent(void)
#endif
