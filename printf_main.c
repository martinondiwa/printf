#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);
int process_format(const char *format, va_list args);

/**
 * _printf - Prints formatted output.
 * @format: Format string.
 *
 * Return: The length of the printed string.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	length = process_format(format, args);

	va_end(args);
	return (length);
}

/**
 * process_format - Processes the format string.
 * @format: Format string.
 * @args: Variable arguments list.
 *
 * Return: The length of the printed string.
 */
int printf_string(va_list args) {
	const char *str = va_arg(args, const char *);
	return printf("%s", str);
}

int print_char(va_list args) {
	char c = va_arg(args, int);
	return printf("%c", c);
}

int print_int(va_list args) {
	int num = va_arg(args, int);
	return printf("%d", num);
}

int process_format(const char *format, va_list args) {
    int i = 0, j, length = 0;

    struct FormatSpecifier p[] = {
        {"%s", printf_string}, {"%c", print_char},
        {"%%", print_int}, {"%i", print_int},
        {"%d", print_int},
        {"%r", print_hexc_string}, {"%R", print_hexc_string},
        {"%b", print_bin}, {"%u", print_unsigned},
        {"%o", print_oct}, {"%x", print_hex}, {"%X", print_hex},
        {"%S", print_pointer}, {"%p", print_pointer}
    };

    while (format[i] != '\0') {
        j = sizeof(p) / sizeof(p[0]) - 1;
        while (j >= 0) {
            if (format[i] == '%' && format[i + 1] == p[j].format[1]) {
                length += p[j].function(args);
                i += 2;
                break;
            }
            j--;
        }

        if (j < 0) {
            putchar(format[i]);
            length++;
            i++;
        }
    }

    return length;
}
