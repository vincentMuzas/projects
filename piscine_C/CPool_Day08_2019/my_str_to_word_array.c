/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_str_to_word_array
*/

#include "libmy.h"
#include <stdlib.h>

int my_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int count_non_alpha(char const *str)
{
    int res = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (!my_is_alpha(str[i]))
            res++;
    }
    return (res + 1);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0, pos, k;
    char **tab;
    if ((tab = malloc(sizeof(char *) * (count_non_alpha(str) + 1))) == NULL)
        return (NULL);
    for (pos = 0; str[i] != 0; pos++) {
        if ((tab[pos] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
            return (NULL);
        while (!(my_is_alpha(str[i])))
            i++;
        for (k = 0; my_is_alpha(str[i]); i++) {
            tab[pos][k] = str[i];
            k++;
        }
        if (str[i] != 0)
            i++;
        tab[pos][k] = 0;
        tab[pos + 1] = 0;
    }
    return (tab);
}