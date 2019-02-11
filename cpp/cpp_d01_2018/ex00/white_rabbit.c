/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** white_rabbit
*/

#include <stdio.h>
#include <stdlib.h>

int follow_the_white_rabbit(void)
{
    int i, count = 0;

    while (1) {
        i = (random() % 37) + 1;
        count += i;
        if (i % 11 == 0 || i == 12)
            continue;
        if (i == 37 || count >= 397 || i == 1)
            break;
        if (i == 23 || i == 15 || i == 10)
            printf("forward\n");
        if (i == 26 || i % 8 == 0)
            printf("backward\n");
        if ((i >= 4 && i <= 6) || i == 28 || (i >= 17 && i <= 21))
            printf("left\n");
        if (i == 13 || i >= 34)
            printf("right\n");
    }
    printf("RABBIT!!!\n");
    return (count);
}