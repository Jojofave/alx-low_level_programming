#include "main.h"
/**
 * _isupper - uppercase letters
 * @c: char to check
 *
 *  Return: 0 or 1
 */
int _isupper(int c)
{
	int i;

	if (c >= 'A' && c <= 'Z')
	{
		i = 1;
		return (i);
	}
	else
	{
		i = 0;
		return (i);
	}
}
