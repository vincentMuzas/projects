/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return (nb);
    if (nb == __INT_MAX__)
        return (0);
    return (my_find_prime_sup(nb + 1));
}