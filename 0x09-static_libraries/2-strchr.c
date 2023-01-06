#include "main.h"
/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */

char *_strchr(char *s, char c)
{
	while (s++)
	{
		if (*s == c)
			return (s);
		if (!*s)
			return (0);
	}
	return (0);
}
