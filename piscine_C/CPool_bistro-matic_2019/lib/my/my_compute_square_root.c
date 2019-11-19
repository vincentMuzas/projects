/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 0)
        return (0);
    while (++i <= 46340 && i * i < nb);
    return ((i * i == nb) ? i : 0);
}
