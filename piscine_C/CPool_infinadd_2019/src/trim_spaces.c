/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** trim_spaces
*/

#include "infin_add.h"

char *trim_spaces(char *str)
{
    if (str == NULL)
        return (NULL);
    char sign = str[0];
    int i = 0;
    char *ret;
    while ((str[i] < '1' || str[i] > '9') && str[i] != 0) {
        i++;
    }
    if (sign == '-') {
        str[i - 1] = '-';
        i--;
    }
    if (my_strcmp(&str[i], "") == 0)
        ret = my_strdup("0");
    else
        ret = my_strdup(&str[i]);
    free(str);
    return (ret);
}