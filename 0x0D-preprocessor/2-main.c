#include <stdio.h>

/**
 *  main - prints the name of the file program was compiled from
 *  Return: Always 0
 */
int main(void) /*don't want a semi colon here*/
{
	printf("%s\n", __FILE__);
	return (0);
}
