#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

#define MAX_BUF_SIZE 1024

int ibuf;
char buf[MAX_BUF_SIZE];
int print_HEX_extra(int value);
int print_hex_extra(int value);

int _putchar(char c);
int handl_buf(char *buf, char c, int ibuf);
int printf_string(va_list val);

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_char(va_list val);	
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_hexc_string(va_list val);
int print_percent(void);
int print_int(va_list args);
int print_bin(va_list val);
int print_unsigned(va_list args);
int print_oct(va_list val);
int print_hex(va_list val);
int print_Hex(va_list val);
int print_pointer(va_list val);
int print_hexa_extra(unsigned long int num);
int print_rev(va_list arguments, char *buf, unsigned int ibuf);
int print_rot(va_list arguments, char *buf, unsigned int ibuf);
int get_size(const char *format, int *i);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);

#define S_LONG 0
#define S_SHORT 1

int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
