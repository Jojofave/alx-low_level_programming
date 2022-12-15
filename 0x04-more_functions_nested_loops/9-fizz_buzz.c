#include <stdio.h>
/**
 * main - Prints the numbers from 1-100 but multiplies of three,
 *        Fizz is printed in place of the no, BUZZ in place of multiples,
 *        of 5 and FizzBuzz for both five and three.
 *
 * Return: Always 0;
 */

int (main)void
{

int p = 100;
int i;

i = 1;
while (i <= p)
{
if (i % 3 == 0 && i % 5 == 0)
{
printf("FizzBuzz");
}

else if (i % 3 == 0)
{
printf("Fizz");
}

else if (i % 5 == 0)
{
if (i < p)
printf("Buzz");

else
printf("%d", i);
}

else
{
printf("%i ", i);
}

i++;


}
printf("\n");
return (0);
}
