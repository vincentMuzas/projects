/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** main
*/

#include "bistro.h"
#include "my.h"
#include <stdio.h>

static char  *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i] != 0; i++) {
        for (int j = i + 1; ops[j] != 0; j++) {
            if (ops[i] == ops[j])
                quitp(SYNTAX_ERROR_MSG, EXIT_BASE);
        }
    }
}

static void check_base(char const *b, char const *ops)
{
    if (my_strlen(b) < 2)
        quitp(SYNTAX_ERROR_MSG, EXIT_BASE);
    for (int i = 0; b[i] != 0; i++) {
        for (int j = i + 1; b[j] != 0; j++) {
            if (b[i] == b[j])
                quitp(SYNTAX_ERROR_MSG, EXIT_BASE);
        }
        for (int j = 0; ops[j] != 0; j++) {
            if (ops[j] == b[i])
                quitp(SYNTAX_ERROR_MSG, EXIT_BASE);
        }
    }
}

int main(int ac, char **av)
{
    bistro_t data;
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1], av[2]);
    check_ops(av[2]);
    data.base = av[1];
    data.operator = av[2];
    data.base_len = my_strlen(av[1]);
    data.calc = get_expr(my_getnbr(av[3]));
    my_putstr(eval_expr(&data));
    return (EXIT_SUCCESS);
}