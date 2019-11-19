/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int x = nb * nb, result;
    if (p > 1) {
        if (nb != 0 && x / nb != nb)
            return (1);
        result = my_compute_power_rec(nb, p - 1);
        x = nb * result;
        if (nb != 0 && x / result != nb)
            return (1);
        return (x);
    }
    return (nb);
}