#include "main.h"
/**
 * is_palindrome - returns true if the given string is a palindrome
 * @s: string to check
 * Return: true if the given string is a palindrome
 */
int is_palindrome(char *s)
{
	int index = 0;
	int len = find_strlen(s);

	if (!(*s))
		return (1);
	return (check_palindrome(s, len, index));
}
