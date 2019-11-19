/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_print_alpha
*/

#include <unistd.h>

int my_print_alpha(void)
{
    int i = 'a';
    while (i <= 'z')
    {
        write(1, &i, 1);
        i++;
    }
    return (0);
}
