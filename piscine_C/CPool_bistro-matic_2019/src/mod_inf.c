/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** mod_inf
*/

#include "bistro.h"

/**
** @brief infinite modulo
**
** @param stc passed to infinite sub, div and mul
** @param x first operand
** @param y second operand
** @return char* result of modulo
*/
char *mod_inf(bistro_t *stc, char *x, char *y)
{
    return (choice_sub(stc, (char *[]){x, choice_mul(stc, (char *[])
        {y, choice_div(stc, (char *[]){x, y}, 0, 0)}, 0, 1)}, 0, 1));
}
