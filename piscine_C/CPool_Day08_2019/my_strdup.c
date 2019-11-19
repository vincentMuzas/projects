/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup
*/

#include "libmy.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));
    if (new == NULL)
        return (NULL);
    for (int i = 0; i <= len; i++) {
        new[i] = str[i];
    }
    return (new);
}