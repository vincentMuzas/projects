/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** drawing
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin,
                    size_t size, uint32_t color)
{
    for (unsigned int y = origin->y; y < origin->y + size; y ++) {
        for (unsigned int x = origin->x; x < origin->x + size; x++) {
            img[y][x] = color;
        }
    }
}