#include "main.h"
/**
 * alloc_grid - Main entry
 * @width: input
 * @height: input
 * Return: 0
 */
char *str_concat(char *s1, char *s2) /*don't want semi colon here*/
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			while (i >= 0)
				free(grid[i--]);
			free(grid);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;

	}
	return (grid);
}
