/*
** EPITECH PROJECT, 2019
** CPool_match-nmatch_2019
** File description:
** match
*/

#include "match.h"
#include "my.h"

static int my_nmatch(char const *s1, char const *s2, int *total)
{
    if (s1[0] == '\0' && s2[0] == '\0') {
        *total +=1;
        return *total;
    }

    if (s2[0] == '*' && s2[1] != '\0' && s1[0] == '\0')
        return *total;

    if (s1[0] == s2[0])
        return my_nmatch(&s1[1], &s2[1], total);

    if (s2[0] == '*')
        return my_nmatch(&s1[1], s2, total) + my_nmatch(s1, &s2[1], total);
    return *total;
}

int nmatch(char const *s1, char const *s2)
{
    int total = 0;
    my_nmatch(s1, s2, &total);
    return (total);
}
