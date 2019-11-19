/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** transform
*/

#include "bistro.h"
#include "my.h"
#include <stdio.h>
#include <string.h>

static char get_operator(bistro_t *data, char c)
{
    char ref[] = "()+-*/%";
    for (int i = 0; data->operator[i] != 0; i++) {
        if (c == data->operator[i])
            return (-ref[i]);
    }
    return (0);
}

static char get_decimal(bistro_t *data, char c)
{
    char *ref = data->base;
    for (int i = 0; ref[i] != 0; i++) {
        if (c == ref[i])
            return (i + 1);
    }
    return (0);
}

char *format_calc(bistro_t *data)
{
    char c;
    for (int i = 0; data->calc[i] != 0; i++) {
        c = get_operator(data, data->calc[i]);
        if (c != 0)
            data->calc[i] = c;
        else {
            c = get_decimal(data, data->calc[i]);
            if (c != 0)
                data->calc[i] = c;
        }
    }
    return (data->calc);
}

char rev_operator(bistro_t *data, char c)
{
    char ref[] = "()+-*/%";
    for (int i = 0; ref[i] != 0; i++) {
        if (c == -ref[i])
            return (data->operator[i]);
    }
    return (-c);
}

char *rev_format_calc(bistro_t *data, char *str)
{
    char *result = my_strdup(str);
    int found = 0, j = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == 1 && found)
            result[j++] = data->base[str[i] - 1];
        else if (str[i] > 1) {
            result[j++] = data->base[str[i] - 1];
            found = 1;
        }
        else if (result[i] < 0)
            result[j++] = rev_operator(data, str[i]);
    }
    result[j] = 0;
    return (result);
}
