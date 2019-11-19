/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_print_revalpha
*/

#include <unistd.h>

int my_print_revalpha(void)
{
    int i = 'z';
    while (i >= 'a')
    {
        write(1, &i, 1);
        i--;
    }
    return (0);
}