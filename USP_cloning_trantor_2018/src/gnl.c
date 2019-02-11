/*
** EPITECH PROJECT, 2018
** cloning_trantor
** File description:
** gnl.c
*/

#include "trantor.h"

int my_len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i += 1;
    return (i);
}

void inistr(char *str, int max)
{
    int i;

    i = 0;
    while (i != max) {
            str[i] = '\0';
            i += 1;
        }
}

char *append_char(char *str, char c)
{
    char *res;
    int i;

    i = 0;
    if ((res = malloc(sizeof(char) * (my_len(str) + 2))) == NULL)
        exit (84);
    inistr(res, my_len(str) + 2);
    while (str[i] != '\0') {
            res[i] = str[i];
            i += 1;
        }
    res[i] = c;
    free(str);
    return (res);
}

char *my_gnl(int fd)
{
    char *str;
    char c = 0, k;
    struct pollfd fds;
    fds.fd = fd;
    fds.events = POLLIN;
    if ((str = malloc(sizeof(char))) == NULL)
        exit (84);
    str[0] = '\0';
    while (keepRunning)
        if (poll(&fds, 1, 5) == 1) {
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
