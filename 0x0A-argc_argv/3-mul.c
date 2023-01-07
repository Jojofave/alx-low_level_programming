#include "main.h"
#include <stdio.h>
/**
 * main - prints the multiplication of two integers
 * @argc: argument count
 * @argv: argument vectoet number
 * Return: 0 if true, 1 if false
 */
int main(int argc, char *argv[]);
{
	int n1 = 0, n2 = 0

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d\n", a * b);
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}
