#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  print_dog - Prints a struct dog.
 *  @d: The struct dog to be printed.
 */
void print_dog(struct dog *d) /*don't want semi colon here*/
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
