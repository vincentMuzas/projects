/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** 
*/

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac > 1) {
		for (int i = 0; av[1][i] != 0; i++) {
			write(1, &av[1][i], 1);
		}
	}
	return (1);

}