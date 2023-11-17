#include "main.h"

/**
 * print_int - Print an integer
 * @args: Variable arguments list
 *
 * Return: Number of characters printed
 */
int print_int(val_list args)
{
	int k = va_arg(args, int);
	int num, last = k % 10, digit, exp = 1;  
        int i = 1;

        k = k / 10;
        num = k;

        if (last < 0)
        {
                _putchar('-');  // Print negative sign
                num = -num;
                k = -k;  // Fix variable name
                last = -last;
                i++;
        }

        if (num > 0)
        {
                // Calculate the highest order of magnitude
                while (num / 10 != 0)
                {
                        exp = exp * 10;
                        num = num / 10;
                }

                num = k;
                while (exp > 0)
                {
                        // Extract each digit and print as character
                        digit = num / exp;
                        _putchar('0' + digit);  // Print digit as a character
                        num = num % exp;  // Fix modulo operation
                        exp = exp / 10;
                        i++;  // Fix variable increment
                }
        }

        _putchar('0' + last);  // Print last as a character

        return i;  // Return the correct variable
}

#include "main.h"

/**
 * print_dec - Print an integer as a decimal
 * @args: Variable arguments list
 *
 * Return: Number of characters printed
 */
int print_dec(val_list args)
{
        int k = va_arg(args, int);
        int num, last = k % 10, digit, exp = 1;  
        int i = 1;

        k = k / 10;
        num = k;

        if (last < 0)
        {
                _putchar('-');  // Add a character to print negative numbers
                num = -num;
                k = -k;  // Fix variable name
                last = -last;
                i++;
        }

        if (num > 0)
        {
                // Calculate the highest order of magnitude
                while (num / 10 != 0)
                {
                        exp = exp * 10;
                        num = num / 10;
                }

                num = k;
                while (exp > 0)
                {
                        // Extract each digit and print as character
                        digit = num / exp;
                        _putchar('0' + digit);  // Print digit as a character
                        num = num % exp;  // Fix modulo operation
                        exp = exp / 10;
                        i++;  // Fix variable increment
                }
        }

        _putchar('0' + last);  // Print last as a character

        return i;  // Return the correct variable
}
