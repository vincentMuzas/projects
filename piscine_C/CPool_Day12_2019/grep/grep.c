/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** grep
*/

#include "grep.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

int grep(char const* search, char const* file)
{
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return (84);
    char *str;
    while ((str = my_gnl(fd)) != NULL) {
        if (my_strstr(str, search)) {
            write(1, file, my_strlen(file));
            write(1, ":", 1);
            write(1, str, my_strlen(str));
            write(1, "\n", 1);
        }
        free(str);
    }
    return (0);
}