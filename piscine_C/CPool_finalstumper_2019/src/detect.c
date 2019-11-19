/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** detect
*/

#include "my.h"
#include "rush3.h"

int middle_is(char *str, char c)
{
    int len;
    if (str == NULL)
      return (1);
    len = my_strlen(str);
    for (int i = 1; i < len - 1; i++) {
        if (str[i] != c)
            return (0);
    }
    return (1);
}


int detect1(liste_t *list)
{
    int len = my_strlen(list->str);
    if (list->str[0] != 'o' || !(len < 2 ||
	    list->str[len - 1] == 'o') || !middle_is(list->str, '-'))
        return (0);
    for (list = list->next; list->next->str != NULL &&
	   list->str != NULL; list = list->next) {
        if (list->str[0] != '|' || !(len < 2 || list->str[len-1] == '|')
	    || !middle_is(list->str, ' '))
            return (0);
    }
    if (list->str == NULL)
        return (1);
    if (list->str[0] != 'o' || !(len < 2 || list->str[len - 1] == 'o')
	|| !middle_is(list->str, '-'))
        return (0);
    return (1);
}
