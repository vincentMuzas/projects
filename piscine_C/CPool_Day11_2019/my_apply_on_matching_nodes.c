/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_apply_on_matching_nodes
*/

#include "mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin, 
                                int (*f)(),
                                void const *data_ref,
                                int (*cmp)())
{
    for (int i = 0; begin; i++) {
        if (cmp(data_ref, begin->data) == 0)
            f(begin->data);
        begin = begin->next;
    }
    return (0);
}