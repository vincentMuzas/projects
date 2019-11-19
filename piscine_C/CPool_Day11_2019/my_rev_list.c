/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_rev_list
*/

#include "mylist.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *res = NULL, *first = *begin, *tmp = NULL;

    if (first->next == NULL || *begin == NULL)
        return;
    for (res = first; res->next != NULL; res = res->next);
    for (linked_list_t *i = first; first->next != NULL; i = first) {
        for (; i->next->next != NULL; i = i->next);
        for (tmp = res; tmp->next != NULL; tmp = tmp->next);
        i->next = NULL;
        tmp->next = i;
    }
    *begin = res;
}