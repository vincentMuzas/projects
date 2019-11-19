/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int res = 1;
    if (nb > 12 || nb < 0)
        return (0);
    for (; nb > 0; nb --)
    {
        res *= nb;
    }
    return (res);
}
