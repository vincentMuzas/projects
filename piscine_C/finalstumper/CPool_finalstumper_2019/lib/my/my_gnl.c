/* 
** EPITECH PROJECT, 2019
** my_gnl
** File description:
** gnl
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static void init_str(char *str, int max)
{
    for (int i = 0; i < max; i++)
        str[i] = '\0';
}

static char *append_char(char *str, char c)
{
    char *res;
    int i;

    res = malloc(sizeof(char) * (my_strlen(str) + 2));
    init_str(res, my_strlen(str) + 2);
    for (i = 0; str[i] != '\0'; i++)
        res[i] = str[i];
    res[i] = c;
    free(str);
    return (res);
}

char *my_gnl(int fd)
{
    char *str = malloc(sizeof(char)), c;
    int k;
    str[0] = '\0';
    if (str[0] == '\n')
        return (str);
    while (1) {
        k = read(fd, &c, 1);
        if (c == '\0' || c == '\n' || k < 1)
            break;
        str = append_char(str, c);
    }
    if (str[0] == '\0' && k < 2) {
        free(str);
        return (NULL);
    }
    return (str);
}
