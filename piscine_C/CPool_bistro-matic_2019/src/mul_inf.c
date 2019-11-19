/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** mul_inf
*/

#include "bistro.h"

/**
** @brief allocate memory for infinite multiplication
**
** @param s1 first operand
** @param s2 second operand
** @return char* allocated string
*/
static char *alloc_mul(char *s1, char *s2)
{
    char *res = NULL;
    int x = my_strlen(s1);
    int y = my_strlen(s2);

    if (x > y)
        res = malloc(sizeof(char) * (x + 2));
    else
        res = malloc(sizeof(char) * (y + 2));
    for (int i = 0; i < ((x > y) ? x : y) + 2; i++)
        res[i] = 0;
    return (res);
}

/**
** @brief infinite multiplication
**
** @param stc used for length of base
** @param s1 first operand
** @param s2 second operand
** @return char* result of multiplication
*/
char *mul_inf(bistro_t *stc, char *s1, char *s2)
{
    char c1 = 0;
    char c2 = 0;
    char *res = alloc_mul(s1, s2);
    unsigned int nb = 0;

    for (int y = 0, i = 0; s2[y] != '\0'; y++, i++) {
        c2 = ((s2[y] == '\0') ? 0 : (s2[y] - 1));
        for (unsigned int x = 0,tmp_it = i,ret = 0; s1[x] != '\0';x++,tmp_it++){
            c1 = ((s1[x] == '\0') ? 0 : (s1[x] - 1));
            nb = c1 * c2 + ret + ((res[tmp_it] == 0) ? 0 : (res[tmp_it] - 1));
            ret = ((nb >= stc->base_len) ? (nb / stc->base_len) : 0);
            nb = ((nb >= stc->base_len) ? (nb % stc->base_len) : nb);
            res[tmp_it] = (char)(1 + nb);
            res[tmp_it + 1] = ((s1[x+1] == 0)?((char)ret +1):(res[tmp_it +1]));
        }
    }
    my_revstr(res);
    return (res);
}
