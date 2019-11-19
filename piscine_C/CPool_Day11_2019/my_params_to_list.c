/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_params_to_list
*/

#include "mylist.h"
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list, *current;
    if ((list = malloc(sizeof(linked_list_t))) == NULL)
        return (NULL);
    current = list;
    for (int i = ac - 1; i >= 0; i--) {
        current->data = av[i];
        current->next = NULL;
        if (i > 0 && (current->next = malloc(sizeof(linked_list_t))) == NULL)
            return (NULL);
        current = current->next;
    }
    return (list);
}