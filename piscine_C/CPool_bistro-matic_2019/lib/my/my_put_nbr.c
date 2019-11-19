/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char);

static int get_digit(int nb, int digit)
{
    int	i;

    i = 0;
    while (i < digit) {
        nb = (int)nb / 10;
        i = i + 1;
    }
    return (nb % 10);
}

int	my_put_nbr(int nb)
{
    int	digit, rest, i, to_disp;
    if (nb == -2147483648)
        return (write(1, "-2147483648", 11));
    to_disp = nb;
    if (nb < 0) {
        my_putchar('-');
        to_disp = to_disp - (2 * to_disp);
    }
    rest = to_disp;
    i = 0;
    while (rest >= 10) {
        rest /= 10;
        i = i + 1;
    }
    while (i >= 0) {
        digit = get_digit(to_disp, i);
        my_putchar(digit + 48);
        i = i - 1;
    }
    return (0);
}
