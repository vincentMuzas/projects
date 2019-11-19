/*
** EPITECH PROJECT, 2019
** CPool_rush2_2019
** File description:
** rush
*/

#include "my.h"
#include "language.h"
#include <stdlib.h>

static int count_alpha(char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z'))
            count++;
    }
    return (count);
}

void my_put_two_digits(float nbr)
{
    my_putstr(" (");
    my_put_nbr(nbr);
    nbr -= (int) nbr;
    nbr *= 100;
    my_putchar('.');
    my_put_nbr(nbr);
    if (nbr < 10)
        my_putchar('0');
    my_putstr("%)\n");
}

double count_ocurances(char const* str, char *to_find, int no_echo)
{
    int counter, i, j;
    double part;
    char find_lowcase[my_strlen(to_find) + 1];
    my_strlowcase(my_strcpy(find_lowcase, to_find));
    for (i = 0; find_lowcase[i] != 0; i++) {
        counter = 0;
        for (j = 0; str[j] != 0; j++)
            if (str[j] == find_lowcase[i])
                counter++;
        part = ((float)counter / (float)count_alpha(str)) * 100;
        if (!no_echo) {
            my_putchar(to_find[i]);
            my_putchar(':');
            my_put_nbr(counter);
            if (count_alpha(str) == 0)
                part = 0;
            my_put_two_digits(part);
        }
    }
    return (part);
}

void print_language(double *lang)
{
    int min = 0;
    for (int i = 0; i < 4; i++) {
        if (lang[i] < lang[min])
            min = i;
    }
    switch (min) {
        case 0:
            my_putstr("=> English\n");
            break;
        case 1:
            my_putstr("=> French\n");
            break;
        case 2:
            my_putstr("=> German\n");
            break;
        default:
            my_putstr("=> Spanish\n");
            break;
    }
}

int main(int argc, char **argv)
{
    double part[] = {0, 0, 0, 0};
    char str[] = {0, 0};
    if (argc < 2)
        return (84);
    argv[1] = my_strlowcase(argv[1]);
    if (argc > 2)
        for (int i = 2; i < argc; i++)
            count_ocurances(argv[1], argv[i], 0);
    for (int i = 0; i < 4; i++) {
        part[i] = 0;
        for (int letter = 'a'; letter <= 'z'; letter++) {
            str[0] = letter;
            part[i] += count_ocurances(argv[1], str, 1) /
                        (languages[i][letter - 'a']);
        }
    }
    print_language(part);
    return 0;
}