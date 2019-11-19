/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_isneg
*/

#include <unistd.h>

int my_isneg(int n)
{
    write(1, (n >= 0) ? "P" : "N", 1);
    return (0);
}
