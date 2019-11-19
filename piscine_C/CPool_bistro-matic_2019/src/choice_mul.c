/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** choice_mul
*/

#include "bistro.h"

static char *my_prepend_char(char *str, char c)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(*res) * (len + 2));

    res[0] = c;
    for (size_t i = 1; str[i - 1] != 0; i++)
        res[i] = str[i - 1];
    res[len + 1] = 0;
    free(str);
    return (res);
}

static char determine_neg(char *str)
{
    char neg = 0;

    for (; str[0] == -'-'; str++)
        neg ^= 1;
    return (neg);
}

char *choice_mul(bistro_t *data, char **s, char f1, char f2)
{
    char neg[2] = {determine_neg(s[0]), determine_neg(s[1])};
    char *res = NULL;
    char *tmp[] = {s[0], s[1]};

    for (; s[0][0] == -'-'; s[0]++);
    for (; s[1][0] == -'-'; s[1]++);
    my_revstr(s[0]);
    my_revstr(s[1]);
    res = mul_inf(data, s[0], s[1]);
    my_del_at_start_of_str(res, 1);
    if ((!neg[0] && neg[1]) || (neg[0] && !neg[1]))
        res = my_prepend_char(res, -'-');
    for (; f1; free(tmp[0]), f1 = 0);
    for (; f2; free(tmp[1]), f2 = 0);
    return (res);
}
