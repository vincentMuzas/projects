/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_del_at_start_of_str
*/

#include "my.h"

void my_del_at_start_of_str(char *str, char del)
{
    for (; str[0] == del;)
        for (size_t i = 0; str[i] != '\0'; i++)
            str[i] = str[i + 1];
}
