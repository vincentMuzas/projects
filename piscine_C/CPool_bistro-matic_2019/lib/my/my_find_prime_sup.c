/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_find_prime_sup
*/

static int m_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2; i <= 46340 && i * i <= nb; i++)
        if (nb % i == 0)
            return (0);
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb >= 46340)
        return (0);
    for (; nb < 46340 && m_prime(nb) != 1; nb++);
    return ((nb < 46340) ? nb : 0);
}
