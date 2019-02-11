/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** menger
*/

#include "my.h"

void print_number(int *nbr, uint32_t **img)
{
    int x = nbr[0], y = nbr[1], size = nbr[2], level = nbr[3];
    point_t origin = {x, y};
    int col = 255 - (255 / level);
    uint32_t color = (col << 24) + (col << 16) + (col << 8) + col;
    draw_square(img, &origin, size / level, color);
}

int fractal(int *data, uint32_t **img, int maxlvl)
{
    int x = data[0], y = data[1], size = data[2], level = data[3];
    int n[] = {size / 3, y + size / 3, x + size / 3, level, size};
    if (level < 1)
        return (0);
    print_number(n, img);
    size /= 3;
    level -= 1;
    fractal((int []){x, y, size, level}, img, maxlvl);
    fractal((int []){x + size, y, size, level}, img, maxlvl);
    fractal((int []){x + 2 * size, y, size, level}, img, maxlvl);
    fractal((int []){x, y + size, size, level}, img, maxlvl);
    fractal((int []){x + 2 * size, y + size, size, level}, img, maxlvl);
    fractal((int []){x, y + 2 * size, size,level}, img, maxlvl);
    fractal((int []){x + size, y + 2 * size, size,level}, img, maxlvl);
    fractal((int []){x + 2 * size, y + 2 * size, size,level}, img, maxlvl);
    return (0);
}
