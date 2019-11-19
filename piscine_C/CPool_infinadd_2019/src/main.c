/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** main
*/

#include "infin_add.h"

int main(int argc, char const *argv[])
{
    char *result;
    if (argc > 2) {
        if ((result = infin_add(argv[1], argv[2])) != NULL) {
            my_putstr(result);
            my_putchar('\n');
            free(result);
        }
    }
    return 0;
}
