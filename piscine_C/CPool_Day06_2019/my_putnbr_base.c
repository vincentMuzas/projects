/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_putnbr_base
*/

#include <unistd.h>

void my_putchar(char);

int my_putnbr_base(int nbr, char const *base)
{
    int res = 0, len = 0;
    while (base[len] != 0)
        len++;
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr > 0) {
        res = nbr % len;
        nbr = nbr / len;
        my_putnbr_base(nbr, base);
        my_putchar(base[res]);
    }
    return (0);
}