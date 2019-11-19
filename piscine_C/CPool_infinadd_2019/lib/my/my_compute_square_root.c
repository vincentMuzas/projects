/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int res = 0;
    for (int i = 0; res <= nb && i < 46340; i++)
    {
        res = i * i;
        if (res == nb)
            return (i);
    }
    return (0);
}