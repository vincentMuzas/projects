/*
** EPITECH PROJECT, 2019
** CPool_match-nmatch_2019
** File description:
** match
*/

#include "match.h"
#include "my.h"

int match(char const *s1, char const *s2)
{
    if (s1[0] == '\0' && s2[0] == '\0')
        return true;

    if (s2[0] == '*' && s2[1] != '\0' && s1[0] == '\0')
        return false;

    if (s1[0] == s2[0])
        return match(&s1[1], &s2[1]);

    if (s2[0] == '*')
        return match(&s1[1], s2) || match(s1, &s2[1]);
    return false;
}