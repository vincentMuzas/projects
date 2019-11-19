/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_print_comb
*/

#include <unistd.h>

void my_putchar(char c);

static void print_after_elem(void)
{
    my_putchar(',');
    my_putchar(' ');
}

int my_print_comb(void)
{
    char a = '0', b = '1', c = '2';
    while (a < '8') {
        if (c > '9') {
            c = '0';
            b ++;
        }
        if (b > '9') {
            b = '0';
            a++;
        }
        if (c > b && b > a) {
            my_putchar(a);
            my_putchar(b);
            my_putchar(c);
            if (a != '7' || b != '8' || c != '9')
                print_after_elem();
        }
        c++;
    }
    return (0);
}