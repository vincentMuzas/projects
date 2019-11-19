/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** main
*/

#include "grep.h"

int main(int argc, char const *argv[])
{
    if (argc < 3)
        return (84);
    for (int i = 2; i < argc; i++) {
        grep(argv[1], argv[i]);
    }
    return 0;
}
