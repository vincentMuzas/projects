/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** gnl
*/

#include <stdlib.h>
#include <unistd.h>

int my_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i += 1;
    return (i);
}

void inistr(char *str, int max)
{
    int i = 0;
    while (i != max)
    {
        str[i] = '\0';
        i += 1;
    }
}

char *append_char(char *str, char c)
{
    char *res;
    int i = 0;
    res = malloc(sizeof(char) * (my_len(str) + 2));
    inistr(res, my_len(str) + 2);
    while (str[i] != '\0')
    {
        res[i] = str[i];
        i += 1;
    }
    res[i] = c;
    free(str);
    return (res);
}

char *my_gnl(int fd)
{
    char *str, c;
    int k;
    str = malloc(sizeof(char));
    str[0] = '\0';
    c = '\0';
    while (1) {
        k = read(fd, &c, 1);
        if (!(c >= 0) || c == '\0' || c == '\n' || k < 1)
            break;
        str = append_char(str, c);
    }
    if (str[0] == '\0' || c < 0) {
        free(str);
        return (NULL);
    }
    return (str);
}
