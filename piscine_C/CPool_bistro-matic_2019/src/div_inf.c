/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** mul_inf
*/

#include "bistro.h"


/**
** @brief infinite division
**
** @param stc used for length of base
** @param s1 first operand
** @param s2 second operand
** @return char* result of division
*/
char *div_inf(bistro_t *stc, char *s1, char *s2)
{
    char *res = my_strdup((char[]){2, 0});
    char *tmp = my_strdup(s2);
    int len = my_strlen(s1);

    for (int tlen = my_strlen(tmp);
        !(tlen == len && my_strcmp(tmp, s1) == 0) ;) {
        tmp = choice_add(stc, (char *[]){tmp, s2}, 1, 0);
        tlen = my_strlen(tmp);
        res = choice_add(stc, (char *[]){res, (char []){2, 0}}, 1, 0);
        if (tlen > len || (tlen == len && my_strcmp(tmp, s1) > 0)) {
            res = choice_add(stc, (char *[]){res, (char[]){-'-', 2, 0}}, 1, 0);
            break;
        }
    }
    free(tmp);
    return (res);
}
