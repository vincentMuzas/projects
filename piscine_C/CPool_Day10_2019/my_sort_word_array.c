/*
** EPITECH PROJECT, 2019
** CPool_Day10_2019
** File description:
** my_sort_word_array
*/

#include "my.h"

void swap_ptr(char **a, char **b)
{
    char *tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
}

int sizeof_array(char **tab)
{
    int i = 0;
    while (tab[i] != 0) {
        i++;
    }
    return (i);
}

int my_sort_word_array(char **tab)
{
    int i, j, size = sizeof_array(tab);
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (my_strcmp(tab[j], tab[j + 1]) > 0)
                swap_ptr(&tab[j], &tab[j+1]);
        }
    }
    return (0);
}