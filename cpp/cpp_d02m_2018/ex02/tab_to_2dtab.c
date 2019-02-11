/*
** EPITECH PROJECT, 2019
** cpp_d02m_2018
** File description:
** tab_to_2dtab
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int i = 0;
    if ((res[0] = malloc(sizeof(int *) * length)) == NULL)
        return;
    for (int y = 0; y < length ; y++) {
        if ((res[0][y] = malloc(sizeof(int) * width)) == NULL)
            return;
        for (int x = 0; x < width; x++) {
            res[0][y][x] = tab[i];
            i++;
        }
    }
}