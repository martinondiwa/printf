#include "main.h"
#include <stdio.h>

/**
 * print_chr - Writes the character 'c' to the standard output.
 * @arguments: Input character to be printed.
 * @buf: Buffer pointer.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: On success, returns 1.
 */
int print_chr(va_list arguments, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(arguments, int);
	handl_buf(buf, c, ibuf);
	return (1);
}
