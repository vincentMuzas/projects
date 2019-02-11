/*
** EPITECH PROJECT, 2018
** strace.c
** File description:
** strace
*/


#include "strace.h"

int is_nb(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (1);
    return (0);
}

void check_args(char **ac, int *flags, pid_t *pid)
{
    if (ac[1][0] == '-') {
        if (ac[1][1] == 's') {
            *flags += 10;
            if (ac[2][0] == '-') {
                *flags += ((ac[2][1] == 'p' && is_nb(ac[3]) == 1) ? 1 : -11);
                *pid = atoi(ac[3]);
            }
        }
        else if (ac[1][1] == 'p') {
            *flags += 1;
            if (is_nb(ac[2]) == 1)
                *flags = -1;
            *pid = atoi(ac[2]);
        }
    }
}

int make_choice(char **ac, char **env, char **names)
{
    pid_t pid;
    int st;
    int flags = 0;

    check_args(ac, &flags, &pid);
        if (flags % 10 == 0) {
        pid = fork();
        if (pid == 0)
            child_func(ac, env, flags);
        else
            tracer(names, pid, &st, flags);
    } else if (flags > 0)
        tracer(names, pid, &st, flags);
    else
        return (84);
    printf("+++ exit with %d +++\n", st);
    return (0);
}

int main(int av, char **ac, char **env)
{
    char **names;

    if (av <= 1)
        return (84);
    names = getsyscalls();
    if (names == NULL)
        return (84);
    return (make_choice(ac, env, names));
}