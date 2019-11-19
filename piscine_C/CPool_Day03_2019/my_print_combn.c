/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_print_combn
*/

#include <unistd.h>
int	my_put_nbr(int nb);

static int power(int nb, int pow)
{
    int res = nb;

    if (pow == 0)
        return (1);
    for (int i = 1; i != pow; i++)
        res *= nb;
    return (res);
}

static int check(int nb, int n)
{
    int i = 1;

    if (nb < power(10, n - 2))
        return (0);
    while (i != n) {
        if (nb % 10 <= (nb / 10) % 10)
            return (0);
        nb /= 10;
        i++;
    }
    return (1);
}

int my_print_combn(int n)
{
    int nb = 0;
    if (n > 10 || n < 0)
        return (1);
    if (n == 0)
        return (0);
    else if (n == 1) {
        write(1, "0\n", 2);
        return (0);
    }
    while (check(++nb, n) == 0);
    write(1, "0", 1);
    my_put_nbr(nb);
    while (nb++ < power(10, n))
        if (check(nb, n) == 1) {
            write(1, ", ", 2);
            if (nb < power(10, n - 1))
                write(1, "0", 1);
            my_put_nbr(nb);
        }
    return (0);
}