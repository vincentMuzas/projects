/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_print_comb2
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_double_digit(int digit)
{
    my_putchar((digit / 10) + '0');
    my_putchar((digit % 10) + '0');
}

int my_print_comb2(void)
{
    char a = 0, b = 1;
    while (a < 100) {
        if (b > 99) {
            b = 0;
            a++;
        }
        if (a < b) {
            my_print_double_digit(a);
            my_putchar(' ');
            my_print_double_digit(b);
            if (a != 98 || b != 99) {
                my_putchar(',');
                my_putchar(' ');
            }
        }
        b++;
    }
    return (0);
}