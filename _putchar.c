#include "main.h"

/**
 * _putchar - Writes the character to stdout
 * @c: The character to print
 *
 * Return: On success, returns 1.
 * On error, returns -1, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
