/*
** EPITECH PROJECT, 2019
** tmp_day10
** File description:
** do-op
*/

#include "my.h"

int add(int a, int b)
{
    my_put_nbr(a + b);
    return (0);
}

int sub(int a, int b)
{
    my_put_nbr(a - b);
    return (0);
}

int div(int a, int b)
{
    if (b != 0)
        my_put_nbr(a / b);
    else {
        my_putstr("Stop: division by zero");
        return (84);
    }
    return (0);
}

int modulo(int a, int b)
{
    if (b != 0)
        my_put_nbr(a % b);
    else {
        my_putstr("Stop: modulo by zero");
        return (84);
    }
    return (0);
}

int main(int argc, char const *argv[])
{
    char op[] = "+-/%";
    int finished = 0, ret = 84;
    int (*fnt[])(int, int) = {&add, &sub, &div, &modulo};
    if (argc != 4) {
        my_putstr("0\n");
        return (ret);
    }
    for (int i = 0; op[i] != 0; i++) {
        if (op[i] == argv[2][0]) {
            ret = fnt[i](my_getnbr(argv[1]), (my_getnbr(argv[3])));
            my_putchar('\n');
            finished = 1;
            break;
        }
    }
    if (!finished)
        my_putstr("0\n");
    return ret;
}
