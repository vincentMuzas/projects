/*
** EPITECH PROJECT, 2019
** CPool_rush1_2019
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>
int rush(int, int);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char const *argv[])
{
    if (argc == 3)
        rush(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
