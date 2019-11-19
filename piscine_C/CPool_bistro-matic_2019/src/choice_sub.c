/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** main
*/

#include "bistro.h"

char *choice_sub(bistro_t *data, char **s, char f1, char f2)
{
    char *res = choice_add(data, (char *[]){s[0], choice_mul(data, (char *[])
        {s[1], (char[]){-'-', 2, 0}}, 0, 0)}, 0, 1);

    if (f1)
        free(s[0]);
    if (f2)
        free(s[1]);
    return (res);
}
