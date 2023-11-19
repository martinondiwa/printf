#include "main.h"

#include "custom_flags.h"

/*
** handle_write_char - Handles writing a single character.
** @c: The character to write.
** @buffer: The buffer to write the character to.
** @flags: Formatting flags.
** @width: Width specification.
** @precision: Precision specification.
** @size: Size specification.
**
** Returns: The number of characters written.
*/
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FD_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFSIZ - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFSIZ - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFSIZ - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFSIZ - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/*
** write_number - Handles writing formatted numbers to a buffer.
** @is_negative: Indicates if the number is negative.
** @ind: Index in the buffer to start writing.
** @buffer: The buffer to write the number to.
** @flags: Formatting flags.
** @width: Width specification.
** @precision: Precision specification.
** @size: Size specification.
**
** Returns: The number of characters written.
*/
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFSIZ - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & FD_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}

/*
** write_num - Handles writing formatted numbers to a buffer.
** @ind: Index in the buffer to start writing.
** @buffer: The buffer to write the number to.
** @flags: Formatting flags.
** @width: Width specification.
** @prec: Precision specification.
** @length: Length of the number.
** @padd: Padding character.
** @extra_c: Extra character to be added (e.g., '+', '-').
**
** Returns: The number of characters written.
*/
int write_num(int ind, char buffer[],
		int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFSIZ - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFSIZ - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/*
** write_unsgnd - Handles writing formatted unsigned numbers to a buffer.
** @is_negative: Indicates if the number is negative.
** @ind: Index in the buffer to start writing.
** @buffer: The buffer to write the number to.
** @flags: Formatting flags.
** @width: Width specification.
** @precision: Precision specification.
** @size: Size specification.
**
** Returns: The number of characters written.
*/
int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFSIZ - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFSIZ - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & FD_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/*
** write_pointer - Handles writing formatted pointers to a buffer.
** @buffer: The buffer to write the pointer to.
** @ind: Index in the buffer to start writing.
** @length: Length of the pointer.
** @width: Width specification.
** @flags: Formatting flags.
** @padd: Padding character.
** @extra_c: Extra character to be added (e.g., '+',
*/
