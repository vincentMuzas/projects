/*
** EPITECH PROJECT, 2019
** cpp_d02a_2018
** File description:
** truc3
*/

#include <stdlib.h>
#include "simple_list.h"

double list_get_elem_at_front(list_t list) {
    if (list == NULL)
        return (0);
    return (list->value);
}

double list_get_elem_at_back(list_t list) {
    if (list == NULL)
        return (0);
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position) {
    for (unsigned int i = 0; i < position && list != NULL; i++)
        list = list->next;
    if (list == NULL)
        return (0);
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, double value) {
    while (list != NULL) {
        if (list->value == value)
            return (list);
        list = list->next;
    }
    return (NULL);
}