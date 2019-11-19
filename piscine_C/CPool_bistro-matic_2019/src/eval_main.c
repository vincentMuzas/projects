/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** main
*/

#include "bistro.h"
#include "my.h"

#include <stdio.h>

char *simplify(bistro_t *data)
{
    char sign = 0;
    int i, j;
    for (i = 0, j = 0; data->calc[i] != 0; i++) {
        if (data->calc[i] == -'-' && sign == -'-') {
            sign = -'+';
            continue;
        }
        if ((data->calc[i] == -'+' || data->calc[i] == -'-') && 
                !(data->calc[i] == -'+' && sign == -'-')) {
            sign = data->calc[i];
            continue;
        }
        if (sign != 0) {
            data->calc[j++] = sign;
            sign = 0;
        }
        if (data->calc[i] != -'-' && data->calc[i] != -'+')
            data->calc[j++] = data->calc[i];
    }
    data->calc[j] = 0;
    return (data->calc);
}

char *eval_expr(bistro_t *data)
{
    char *result, *ret;
    data->calc = format_calc(data);
    data->calc = simplify(data);
    check_parenthesis(data->calc);
    result = expression(data, &data->calc);
    ret = rev_format_calc(data, result);
    free(result);
    return (ret);
}

void quitp(char *message, int code)
{
    my_putstr(message);
    exit(code);
}
