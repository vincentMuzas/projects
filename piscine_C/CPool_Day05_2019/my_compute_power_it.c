/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_power_it
*/

int my_compute_power_it(int nb, int p)
{
    int res = 1;
    if (p < 0)
        return (0);
    for (;p > 0; p--)
    {
        res *= nb;
    }
    return (res);
}