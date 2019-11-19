/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_isneg
*/

#include <unistd.h>

int my_isneg(int n)
{
    char disp = (n < 0) ? 'N' : 'P';
    write (1, &disp, 1);
    return (0);
}
