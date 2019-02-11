/*
** EPITECH PROJECT, 2018
** cloning_trantor
** File description:
** utils
*/

#include "trantor.h"

int str_is_digit(char *str) {
    int i = 0;
    while (str[i] != 0) {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

char *getArg(char **av, int ac, char *what) {
    int i = 1;
    while (i < ac - 1) {
        if (!strcmp(av[i], what)) {
            if (str_is_digit(av[i + 1]))
                return (av[i + 1]);
        }
        i+=2;
    }
    return (0);
}

args_t args(char **av)
{
    args_t args;

    args.size[0] = atoi(getArg(av, 7, "-w"));
    args.size[1] = atoi(getArg(av, 7, "-h"));
    args.port = getArg(av, 7, "-p");
    listen_port = atoi(args.port);
    args.error = !(args.size[0] && args.size[1] && args.port);
    return (args);
}

int helper(int ac, char **av) {
    if (ac == 2 && strcmp(av[1], "--help") == 0) {
        printf("%s -h [height] -w [width] -p [port]\n", av[0]);
        return (84);
    }
    return (0);
}