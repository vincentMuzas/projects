/*
** EPITECH PROJECT, 2019
** CPool_rush1_2019
** File description:
** rush
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char *str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        my_putchar(str[i]);
    }
}

void print_line(char first, char last, char normal, int count)
{
    if (count == 1)
    {
        my_putchar(normal);
        my_putchar('\n');
        return;
    }
    my_putchar(first);
    for (int i = 2; i < count; i++) {
        my_putchar(normal);
    }
    if (count > 1)
        my_putchar(last);
    my_putchar('\n');
}

int rush(int x, int y)
{
    if (y > 1 && x > 0) {
        print_line('A', 'C','B', x);
        for (int p = 0; p < y - 2; p++) {
            if (x == 1)
                print_line('B', 'B', 'B', x);
            else
                print_line('B', 'B', ' ', x);
        }
        if (y >= 2)
            print_line('A', 'C', 'B', x);
    }
    else if (y == 1 && x > 0) {
        print_line('B', 'B', 'B', x);
    }
    else
        my_putstr("Invalid size\n");
    return (0);
}
