/*
** EPITECH PROJECT, 2018
** menger
** File description:
** 
*/

#include "my.h"

void print_number(int nbr, char end)
{
	printf("%i%i%i%c", nbr % 1000 / 100, nbr % 100 /10, nbr % 10, end);
}

int fractal(int x, int y, int size, int level)
{
	if (level < 1)
		return (0);
	print_number(size / 3, ' ');
	print_number(y + size / 3, ' ');
	print_number(x + size / 3, '\n');
	size /= 3;
	level -= 1;
	fractal(x, y, size, level);
	fractal(x + size, y, size, level);
	fractal(x + 2 * size, y, size, level);
	fractal(x, y + size, size, level);
	fractal(x + 2 * size, y + size, size, level);
	fractal(x, y + 2 * size, size,level);
	fractal(x + size, y + 2 * size, size,level);
	fractal(x + 2 * size, y + 2 * size, size,level);
	return (0);
}
