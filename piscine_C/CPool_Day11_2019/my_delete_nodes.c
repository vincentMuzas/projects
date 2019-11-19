/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_delete_nodes
*/

#include "mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *ptr = begin[0]->next;
    for (int i = 0; begin; i++) {
        if (cmp(data_ref[i], begin->data) == 0) {

        }
    }
}