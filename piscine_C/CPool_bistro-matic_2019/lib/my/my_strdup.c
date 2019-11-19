/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char *);
char *my_strcpy(char *, char *);

char *my_strdup(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(res, str);
    return (res);
}
