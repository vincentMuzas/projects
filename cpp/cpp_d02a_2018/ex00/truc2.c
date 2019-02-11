/*
** EPITECH PROJECT, 2019
** cpp_d02a_2018
** File description:
** truc2
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_add_elem_at_position(list_t *front_ptr, double elem, 
                                    unsigned int position) {
    list_t loc = front_ptr[0], next;
    unsigned int i = 1;
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    
    while (i < position && loc != NULL && loc->next != NULL) {
        loc = loc->next;
        i++;
    }
    if (i != position)
        return (FALSE);
    next = loc->next;
    if ((loc->next = malloc(sizeof(node_t))) == NULL)
        return (FALSE);
    loc->next->value = elem;
    loc->next->next = next;
    return (TRUE);
}

bool_t list_del_elem_at_front(list_t *front_ptr) {
    if (front_ptr[0] == NULL) {
        return (FALSE);
    }
    list_t next = front_ptr[0]->next;
    free(front_ptr[0]);
    front_ptr[0] = next;
    return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr) {
    if (front_ptr[0] == NULL)
        return (FALSE);
    list_t loc = front_ptr[0], prev = loc;

    while (loc != NULL && loc->next != NULL) {
        prev = loc;
        loc = loc->next;
    }
    free(loc);
    prev->next = NULL;
    return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position) {
    list_t loc = front_ptr[0], next;
    unsigned int i = 1;
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    
    while (i < position && loc != NULL && loc->next != NULL) {
        loc = loc->next;
        i++;
    }
    if (i != position || loc == NULL || loc->next == NULL)
        return (FALSE);
    if (loc->next == NULL)
        next = NULL;
    else
        next = loc->next->next;
    free(loc->next);
    loc->next = next;
    return (TRUE);
}