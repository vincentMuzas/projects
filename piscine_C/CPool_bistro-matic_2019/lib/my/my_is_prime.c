/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2; i <= 46340 && i * i <= nb; i++)
        if (nb % i == 0)
            return (0);
    return (1);
}
