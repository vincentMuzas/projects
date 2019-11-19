/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** detect5
*/

#include "my.h"
#include "rush3.h"

int detect5(liste_t *list)
{
    int len = my_strlen(list->str);
    if (len == 1) {
        for (; list->str != NULL; list = list->next)
            if (list->str[0] != 'B')
                return (0);
        return (1);
    }
    if (list->next->str == NULL)
        return (detect_line(list->str, 'B'));
    if (list->str[0] != 'A' || !(len < 2 || list->str[len - 1] == 'C')
	|| !middle_is(list->str, 'B'))
        return (0);
    for (list = list->next; list->next->str != NULL; list = list->next) {
        if (list->str[0] != 'B' || !(len < 2 || list->str[len-1] == 'B')
	    || !middle_is(list->str, ' '))
            return (0);
    }
    if (list->str[0] != 'C' || !(len < 2 || list->str[len - 1] == 'A')
	|| !middle_is(list->str, 'B'))
        return (0);
    return (1);
}
