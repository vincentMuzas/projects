/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_print_digits
*/

#include <unistd.h>

int my_print_digits(void)
{
    int i = '0';
    while (i <= '9')
    {
        write(1, &i, 1);
        i++;
    }
    return (0);
}
