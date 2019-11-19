/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_show_word_array
*/

#include "libmy.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++)
    {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}