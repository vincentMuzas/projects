/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** main
*/

#include "my.h"

int main(int av, char **ac)
{
    int size, level;
    if (av != 4 || !is_number(ac[2]) || !is_number(ac[3]))
        return (84);
    size = my_getnbr(ac[1]);
    level = my_getnbr(ac[2]);
    unsigned int *buffer = malloc(size * size * 9 * sizeof (*buffer));
    unsigned int **img = malloc(size * 3 * sizeof (*img));
    create_image(size , buffer , img);
    create_bitmap_from_buffer(size , buffer);
    if ((level * level * level) > size)
        return (84);
    fractal((int[]){0, 0, size, level}, img, level);
    return (0);
}
