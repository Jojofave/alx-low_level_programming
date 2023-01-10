#include "main.h"
/**
 * _strlen - count array
 * @s: array of elements
 * Return: i
 */
int _strlen(char *s) /*don't want semi colon here*/
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0') /*count character of string*/
	{
		i++;
	}
	return (i);
}

/**
 * str_concat - back a pointer to array
 * @s1: Array one
 * @s2: Array two
 * Return: Always an array dinamic
 */
char *str_concat(char *s1, char *s2) /*don't want semi colon here*/
{
	char *dst;
	unsigned int i, j, size;

	/*if the array is empty*/
	if (s1 == NULL)
		s1  = "";

	if (s2 == NULL)
		s2 = "";

	/*count size total*/
	size = (_strlen(s1) + _strlen(s2) + 1);

			/*malloc*/
			dst = (char *)malloc(size * sizeof(char));

	if (dst == 0)

		return (NULL);

	/*concatenate arrays*/
	for (i = 0; *(s1 + i) != '\0'; i++)
	*(dst + 1) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{	
	        *(dst + 1) = *(s2 + j);
	        i++;
	}

	return (dst);
}
