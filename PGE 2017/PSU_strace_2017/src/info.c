/*
** EPITECH PROJECT, 2018
** strace
** File description:
** info
*/

#include "strace.h"

char **append_chartab(char **tab, char *str)
{
    char **res;
    size_t i;

    for (i = 0; tab[i] != NULL; i++);
    res = malloc(sizeof(char *) * (i + 2));
    for (i = 0; tab[i] != NULL; i++)
        res[i] = tab[i];
    res[i] = str;
    res[i + 1] = NULL;
    free(tab);
    return (res);
}

char *append_char(char *str, char c)
{
    size_t i;
    char *res;

    for (i = 0; str[i] != '\0'; i++);
    res = calloc(i + 2, sizeof(char));
    for (i = 0; str[i] != '\0'; i++)
        res[i] = str[i];
    res[i] = c;
    return (res);
}

char **getsyscalls_loop(char **res, char *str, int fd)
{
    char tmp;
    size_t count = 0;

    while (read(fd, &tmp, 1) == 1) {
        if (tmp == '/')
            count++;
        if (count == 3) {
            if (tmp == '\n' && str[0] != '\0') {
                res = append_chartab(res, str);
                str = malloc(sizeof(char));
                str[0] = '\0';
            } else if (tmp != ' ' && tmp != '*' && tmp != '/' && tmp != '\n')
                str = append_char(str, tmp);
        }
    }
    return (res);
}

char **getsyscalls(void)
{
    char **res;
    char *str;
    int fd;

    str = malloc(sizeof(char));
    res = malloc(sizeof(char *));
    str[0] = '\0';
    res[0] = NULL;
    fd = open("./includes/strace.h", O_RDONLY);
    return (getsyscalls_loop(res, str, fd));
}

long int takeinfo(int nb, pid_t pid)
{
    long unsigned int tab[7] = { sizeof(long) * RAX, sizeof(long) * RDI,
                                sizeof(long) * RSI, sizeof(long) * RDX,
                                sizeof(long) * R10, sizeof(long) * R8,
                                sizeof(long) * R9 };
    
    return (ptrace(PTRACE_PEEKUSER, pid, tab[nb], 0));
}