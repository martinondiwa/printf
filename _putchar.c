#include "main.h"

/**
 * _putchar - Writes the character 'c' to stdout
 * @c: The character to print
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
e
	return (write(1, &c, 1));
}
