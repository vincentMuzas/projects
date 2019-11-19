/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** eval_expr
*/

#include "eval_expr.h"

static char get(char **expr)
{
    return (*(*expr)++);
}

static int number(char **expr)
{
    int result = get(expr) - '0';
    while (**expr >= '0' && **expr <= '9')
        result = 10*result + get(expr) - '0';
    return (result);
}

static int factor(char **expr)
{
    int result;

    if (**expr >= '0' && **expr <= '9')
        return (number(expr));
    else if (**expr == '(') {
        get(expr);
        result = expression(expr);
        get(expr);
        return (result);
    }
    else if (**expr == '-') {
        get(expr);
        return (-factor(expr));
    }
    return (0);
}

static int term(char **expr)
{
    int result = factor(expr);
    char c;
    while (**expr == '*' || **expr == '/' || **expr == '%') {
        c = get(expr);
        if (c == '*')
            result *= factor(expr);
        else if (c == '/')
            result /= factor(expr);
        else
            result %= factor(expr);
    }
    return (result);
}

int expression(char **expr)
{
    int result = term(expr);
    while (**expr == '+' || **expr == '-')
        if (get(expr) == '+')
            result += term(expr);
        else
            result -= term(expr);
    return (result);
}
