#include "main.h"

/**
 * printf_string - Writes the given string to the standard output.
 * @val: Argument list containing the string to be printed.
 *
 * Return: On success, returns the number of characters printed.
 */
int printf_string(val_list val)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(val, char *);

	if (str == NULL)
	{
		/* Handle NULL string by printing "(null)" */
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);

		return (6);
	}

	/* Iterate through the characters of the string and print each one */
	for (i = 0; str[i]; i++)
		ibuf = handl_buf(buf, str[i], ibuf);

	return (i);
}
