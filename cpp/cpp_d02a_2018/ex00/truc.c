/*
** EPITECH PROJECT, 2019
** cpp_d02a_2018
** File description:
** truc
*/

#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(list_t list) {
    unsigned int i = 0;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}

bool_t list_is_empty(list_t list) {
    return ((list == NULL) ? TRUE : FALSE);
}

void list_dump(list_t list) {
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool_t list_add_elem_at_front(list_t *front_ptr, double elem) {
    list_t first = front_ptr[0];
    if ((front_ptr[0] = malloc(sizeof(node_t))) == NULL)
        return (FALSE);
    front_ptr[0]->value = elem;
    front_ptr[0]->next = first;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem) {
    list_t loc = front_ptr[0];

    while (loc != NULL && loc->next != NULL) {
        loc = loc->next;
    }
    if (loc != NULL) {
        if ((loc->next = malloc(sizeof(node_t))) == NULL)
            return (FALSE);
        loc->next->value = elem;
        loc->next->next = NULL;
        return (TRUE);
    }
    return (list_add_elem_at_front(front_ptr, elem));
}
