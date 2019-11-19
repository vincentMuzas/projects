/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** main
*/

#include "eval_expr.h"

int eval_expr(char const *str)
{
    char *expr = my_strdup(str);
    void *ptr = expr;
    int result;
    my_epur_str(expr);
    result = expression(&expr);
    free(ptr);
    return (result);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        my_put_nbr(eval_expr(argv[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
