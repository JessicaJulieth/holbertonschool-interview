#include "menger.h"

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: Is the level of the Menger Sponge to draw
 * Return: nothing
 */
void menger(int level)
{
	int x, y, z;

	if (level < 0)
		return;
	z = pow(3, level);
	for (x = 0; x < z; x++)
	{
		for (y = 0; y < z; y++)
			printf("%c", space(x, y));
		putchar(10);
	}
}


/**
 * space - gets a character
 * @x: column
 * @y: row
 * Return: '#' or ' '
 */
char space(int x, int y)
{
	while (x && y)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (' ');
		x /= 3, y /= 3;
	}
	return ('#');
}
