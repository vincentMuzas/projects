/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add
*/

#include "infin_add.h"

static char get_sign(char const *str)
{
    char sign = 1;
    for (int i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            sign *= -1;
    }
    return (sign);
}

static int numlen(char const *str)
{
    int i;
    for (i = 0; str[i] == '+' || str[i] == '-'; i++);
    return (my_strlen(str) - i);
}

char *my_memset(char *s, int c, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        s[i] = c;
    }
    return (s);
}

static char *infin_add_sequel(char const *s1, char const *s2)
{
    int lenres = my_strlen(s1) + 1, len1 = my_strlen(s1), len2 = my_strlen(s2);
    char *result = malloc((lenres + 1) * sizeof(char));
    char sign1 = get_sign(s1), sign2 = get_sign(s2), keep = 0;
    if (result == NULL)
        return (NULL);
    my_memset(result, '0', lenres + 1);
    for (; lenres >= 0; lenres--, len1--, len2--) {
        if (len1 >= 0 && ISNUM(s1[len1]))
            result[lenres] += (s1[len1] - '0') * sign1;
        if (len2 >= 0 && ISNUM(s2[len2]))
            result[lenres] += (s2[len2] - '0') * sign2;
        result[lenres] += keep;
        keep = 0;
        for (; result[lenres] > '9'; result[lenres] -= 10, keep += 1);
        for (; result[lenres] < '0'; result[lenres] += 10, keep -= 1);
    }
    result[my_strlen(s1) + 1] = 0;
    return (result);
}

char *infin_add(char const *str1, char const *str2)
{
    int len1 = numlen(str1), len2 = numlen(str2);
    char *result;
    if (MAX(len1, len2) == len1)
        result = infin_add_sequel(str1, str2);
    else
        result = infin_add_sequel(str2, str1);
    return(trim_spaces(result));
}