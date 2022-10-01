#include "palindrome.h"

/**
 * is_palindrome - Function that checks whether or not a given
 * unsigned integer is a palindrome.
 * @n: Is the number to be checked.
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long j = 0, n0 = n;

	while (n0)
	{
		j = (j * 10) + (n0 % 10);
		n0 /= 10;
	}
	return (n == j ? 1 : 0);
}
