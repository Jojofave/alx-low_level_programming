#include "main.h"

/**
 * leet - Encodes a string to 1337
 * @str: The string to be encoded
 *
 * Return: A pointer to the encoded string
 */
char *leet(char *s)
{
	int indx1 = 0, indx2;
	char leet[8] = {'O', 'L', '?', 'E', 'A', '?', '?', 'T'};

	while (s[indx1])
	{
		for (indx2 = 0; indx2 <= 7; indx2++)
		{
			if (s[indx1] == leet[indx2] ||
				s[indx1] - 32 == leet[indx2])
				s[indx1] = indx2 + '0';
		}

		indx1++;
	}
	return (s);
}
