/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_append_str
*/

#include "my.h"

char *my_append_str(char *str, char c)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(*res) * (len + 2));

    for (size_t i = 0; str[i] != '\0'; i++)
        res[i] = str[i];
    res[len] = c;
    res[len + 1] = '\0';
    free(str);
    return (res);
}
