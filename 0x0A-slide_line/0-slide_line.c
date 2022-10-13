#include "slide_line.h"

/**
 * slide_line - slides a line either left or right
 * @line: Input
 * @size: Size
 * @direction: Direction
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	direction == SLIDE_LEFT ? slide_left(line, size)
		: slide_right(line, size);
	return (1);
}

/**
 * slide_left - Line to the left
 * @line: Input
 * @size: Size
 */
void slide_left(int *line, size_t size)
{
	int i = 0, x, y = 0, z;

	for (x = 0; x < (int)size; x++)
	{
		z = line[x];
		if (!z)
			continue;
		if (!y)
			y = z;
		else if (y == z)
		{
			line[i++] = z << 1;
			y = 0;
		} else
		{
			line[i++] = y;
			y = z;
		}
	}
	if (y)
		line[i++] = y;
	while (i < (int)size)
		line[i++] = 0;
}

/**
 * slide_right - Line to the right
 * @line: Input
 * @size: Size
 */
void slide_right(int *line, size_t size)
{
	int y = 0, i = size - 1, x, z;

	for (x = size - 1; x >= 0; x--)
	{
		z = line[x];
		if (!z)
			continue;
		if (!y)
			y = z;
		else if (y == z)
		{
			line[i--] = z << 1;
			y = 0;
		} else
		{
			line[i--] = y;
			y = z;
		}
	}
	if (y)
		line[i--] = y;
	while (i >= 0)
		line[i--] = 0;
}