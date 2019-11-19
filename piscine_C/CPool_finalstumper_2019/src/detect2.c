/*
** EPITECH PROJECT, 2019
** rush3 
** File description:
** detect2
*/

#include "my.h"
#include "rush3.h"

int detect_line(char *str, char c)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] != c)
            return (0);
    return (1);
}


int detect2(liste_t *list)
{
    int len = my_strlen(list->str);
    if (len == 1) {
        for (; list->str != NULL; list = list->next)
            if (list->str[0] != '*')
                return (0);
        return (1);
    }
    if (list->next->str == NULL)
        return (detect_line(list->str, '*'));
    if (list->str[0] != '/' || !(len < 2 ||
	    list->str[len - 1] == '\\') || !middle_is(list->str, '*'))
        return (0);
    for (list = list->next; list->next->str != NULL; list = list->next)
        if (list->str[0] != '*' || !(len < 2 ||
	    list->str[len-1] == '*') || !middle_is(list->str, ' '))
            return (0);
    if (list->str[0] != '\\' || !(len < 2 || list->str[len - 1] == '/') ||
	    !middle_is(list->str, '*'))
        return (0);
    return (1);
}
