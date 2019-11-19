/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** my_show_param_array
*/

#include "my.h"

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str != 0; i++) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        for (int j = 0; par[i].word_array[j] != 0; j++) {
            my_putstr(par[i].word_array[j]);
            my_putchar('\n');
        }
    }
    return (0);
}