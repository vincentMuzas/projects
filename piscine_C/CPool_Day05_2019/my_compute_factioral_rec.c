/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_factioral_rec
*/

int my_compute_factorial_rec(int nb)
{
    if (nb >= 13)
        return (0);
    if (nb > 0)
        return (nb * my_compute_factorial_rec(nb - 1));
    else if (nb == 0)
        return (nb + 1);
    return (0);
}