/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** concat_params
*/

#include "libmy.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int len = 0, j = 0;
    char *new;
    for (int i = 0; i < argc; i++) {
        len += my_strlen(argv[i]) + 1;
    }
    if ((new = malloc(sizeof(char) * len)) == NULL)
        return (NULL);
    for (int i = 0; i < argc; i++) {
        my_strcpy(&new[j], argv[i]);
        j+= my_strlen(argv[i]);
        if (i + 1 < argc) {
            new[j] = '\n';
            j++;
        }
    }
    new[j] = 0;
    return new;
}