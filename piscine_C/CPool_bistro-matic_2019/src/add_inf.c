/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** add_inf
*/

#include "bistro.h"

/**
** @brief allocate memory for infinite addition
**
** @param s1 first operand
** @param s2 second operand
** @return char* allocated string
*/
static char *alloc_add(char *s1, char *s2)
{
    char *res = NULL;
    int x = my_strlen(s1);
    int y = my_strlen(s2);

    if (x > y)
        res = malloc(sizeof(char) * (x + 2));
    else
        res = malloc(sizeof(char) * (y + 2));
    for (int i = 0; i != ((x > y) ? x : y) + 2; i++)
        res[i] = 0;
    return (res);
}

/**
** @brief infinite addition
**
** @param stc used for length of base
** @param s1 first operand
** @param s2 second operand
** @return char* result of addition
*/
char *add_inf(bistro_t *stc, char *s1, char *s2)
{
    char ret = 0;
    char c1 = 0;
    char c2 = 0;
    char nb = 0;
    char *res = alloc_add(s1, s2);

    for (int x = 0, y = 0, i = 0; s1[x] != '\0' || s2[y] != '\0'; x++,y++,i++) {
        c1 = ((s1[x] == '\0') ? 0 : (s1[x] - 1));
        c2 = ((s2[y] == '\0') ? 0 : (s2[y] - 1));
        nb = c1 + c2 + ret;
        ret = ((nb >= (char)stc->base_len) ? 1 : 0);
        nb = ((nb >= (char)stc->base_len) ? (nb - (char)stc->base_len) : nb);
        res[i] = (1 + nb);
        x = ((s1[x] == '\0') ? (x - 1) : x);
        y = ((s2[y] == '\0') ? (y - 1) : y);
        if (s1[x + 1] == 0 && s2[y + 1] == 0)
            res[i + 1] = (ret) ? ret + 1 : 0;
    }
    return (my_revstr(res));
}
