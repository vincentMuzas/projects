/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** my_params_to_array
*/

#include "my_macro_abs.h"
#include "my.h"

#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *arr;
    arr = malloc(sizeof(struct info_param) * (ac + 1));
    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < ac; i++) {
        arr[i].length = my_strlen(av[i]);
        arr[i].str = av[i];
        arr[i].copy = my_strdup(av[i]);
        arr[i].word_array = my_str_to_word_array(av[i]);
        arr[i + 1].str = 0;
    }
    return (arr);
}