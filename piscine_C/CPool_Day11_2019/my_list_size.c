/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_list_size
*/

#include "mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    int i;
    for (i = 0; begin != NULL; i++)
        begin = begin->next;
    return (i);
}