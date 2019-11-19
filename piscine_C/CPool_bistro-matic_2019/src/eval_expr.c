/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** eval_expr
*/

#include "bistro.h"
#include <stdio.h>

/**
** @brief get the current character and move to the next
**
** @param expr string
** @return char return the current character
*/
static char get(char **expr)
{
    return (*(*expr)++);
}

/**
** @brief copy the next number and return a pointer to the copy
**
** @param char **expr
** @return char*
*/
static char *number(char **expr)
{
    int len = my_strlen(*expr), i;
    char *result = malloc(sizeof(char) * len + 1);
    for (i = 0; **expr >= 1; i++)
        result[i] = get(expr);
    result[i] = 0;
    return (result);
}

/**
** @brief handle the parentheses priority
**
** @param data
** @param expr
** @return char* result of the function
*/
static char *factor(bistro_t *data, char **expr)
{
    char *result;
    if (**expr >= 1)
        return (number(expr));
    else if (**expr == -'(') {
        get(expr);
        result = expression(data, expr);
        get(expr);
        return (result);
    }
    else if (**expr == -'-') {
        get(expr);
        return (choice_mul(data, (char *[]){(char[]){-'-', 2, 0},
                                factor(data, expr)}, 0, 1));
    }
    result = my_strdup((char []){1, 0});
    return (result);
}

/**
** @brief call to div, mult or mod inf functions
**
** @param data
** @param expr
** @return char* result of the function
*/
static char *term(bistro_t *data, char **expr)
{
    char *res = factor(data, expr);
    char c;
    while (**expr == -'*' || **expr == -'/' || **expr == -'%') {
        c = get(expr);
        if (c == -'*')
            res = choice_mul(data, (char *[]){res, factor(data, expr)},1,1);
        else if (c == -'/')
            res = choice_div(data, (char *[]){res, factor(data, expr)},1,1);
        else
            res = choice_mod(data, (char *[]){res, factor(data, expr)},1,1);
    }
    return (res);
}

/**
** @brief handle expression
**
** @param bistro_t data
** @param char ** expr
** @return char* result of the function
*/
char *expression(bistro_t *data, char **expr)
{
    char *result = term(data, expr);
    while (**expr == -'+' || **expr == -'-') {
        if (get(expr) == -'+')
            result = choice_add(data, (char *[]){result, term(data,expr)}, 1,1);
        else
            result = choice_sub(data, (char *[]){result, term(data,expr)}, 1,1);
    }
    return (result);
}
