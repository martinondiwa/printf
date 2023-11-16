#include "main.h"

/*************** PRINTING  C *****************/

/**
 * print_c - Prints a single character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);
int print_c(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/***************** PRINTING S ***************/

/**
 * print_s - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);
int print_s(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/*************** PRINTING % *******************/
/**
 * print_percent - Prints a percent sign
 * @types: List of arguments (unused)
 * @buffer: Buffer array to handle print (unused)
 * @flags: Calculates active flags (unused)
 * @width: Width (unused)
 * @precision: Precision specification (unused)
 * @size: Size specifier (unused)
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	(void)types;
	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	return (write(1, "%%", 1));
}
