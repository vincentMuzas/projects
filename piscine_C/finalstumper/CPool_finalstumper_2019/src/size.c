/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** size function
*/

#include "my.h"
#include "rush3.h"

int size(liste_t *liste)
{
    int i = 0;
    int x = 0;
    int y = 0;
    while (liste->str != NULL) {
        x = (my_strlen(liste->str));
        i++;
        liste = liste->next;
    }
    y = i;
    my_putchar(' ');
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    return (0);
}
