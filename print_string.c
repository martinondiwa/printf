#include "main.h"

/**
 * print_str - Writes the given string to the standard output.
 * @arguments: Input string to be printed.
 * @buf: Buffer pointer.
 * @ibuf: Index for the buffer pointer.
 *
 * Return: On success, returns the number of characters printed.
 */
int print_str(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(arguments, char *);

	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (6);
	}

	for (i = 0; str[i]; i++)
		ibuf = handl_buf(buf, str[i], ibuf);

	return (i);
}
