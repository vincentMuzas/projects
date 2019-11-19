/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** main
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

static char determine_aneg(char *s1, char *s2)
{
    char neg1 = 0;
    char neg2 = 0;
    char x;
    char y;
    for (; s1[0] == -'-'; s1++, neg1 ^= 1);
    for (; s2[0] == -'-'; s2++, neg2 ^= 1);
    x = my_strlen(s1);
    y = my_strlen(s2);
    s1 = my_revstr(s1);
    s2 = my_revstr(s2);
    if (neg1 && neg2)
        return (1);
    if (neg1 && ((x < y) || (x == y && my_strcmp(s1, s2) < 0)))
        return (0);
    if (neg2 && ((x > y) || (x == y && my_strcmp(s1, s2) > 0)))
        return (0);
    if (!neg1 && !neg2)
        return (0);
    return (1);
}

static char determine_neg(char *str)
{
    char neg = 0;

    for (; str[0] == -'-'; str++)
        neg ^= 1;
    return (neg);
}

static char *choice_add_conf(char **s, char **str, char *neg, bistro_t *data)
{
    char *res;
    int x;
    int y;

    x = my_strlen(str[0]);
    y = my_strlen(str[1]);
    if (!neg[0] && !neg[1])
        res = add_inf(data, s[0], s[1]);
    else if (neg[0] && neg[1])
        res = add_inf(data, s[0], s[1]);
    else {
        if (x > y)
            res = sub_inf(data, s[0], s[1]);
        else if (x < y)
            res = sub_inf(data, s[1], s[0]);
        else
            res = sub_inf(data, ((my_strcmp(str[0], str[1]) < 0) ? s[1] : s[0]),
                ((my_strcmp(str[0], str[1]) < 0) ? s[0] : s[1]));
    }
    return (res);
}

/**
** @brief prepare for addition
**
** @param data struct of data
** @param s operands
** @param f1 if first operand must be freeded
** @param f2 if second operand must be freeded
** @return char *result of addition
*/
char *choice_add(bistro_t *data, char **s, char f1, char f2)
{
    char **str = malloc(sizeof(*str) * 2);
    char neg[2] = {determine_neg(s[0]), determine_neg(s[1])};
    char aneg = determine_aneg(s[0], s[1]);
    char *res = NULL;
    char *tmp[] = {s[0], s[1]};
    for (; s[0][0] == -'-'; s[0]++);
    for (; s[1][0] == -'-'; s[1]++);
    str[0] = my_strdup(s[0]);
    str[1] = my_strdup(s[1]);
    my_revstr(str[0]);
    my_revstr(str[1]);
    res = choice_add_conf(s, str, neg, data);
    my_del_at_start_of_str(res, 1);
    res = ((aneg) ? my_prepend_char(res, -'-') : res);
    for (; f1; free(tmp[0]), f1 = 0);
    for (; f2; free(tmp[1]), f2 = 0);
    free(str[0]);
    free(str[1]);
    free(str);
    return (res);
}
