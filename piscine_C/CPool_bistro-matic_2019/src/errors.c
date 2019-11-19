/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** errors
*/

#include "bistro.h"
#include "my.h"

void check_parenthesis(char *str)
{
    int par, i;

    for (par = 0, i = 0; str[i] != 0; i++) {
        switch (str[i]) {
            case -'(':
                par++;
                break;
            case -')':
                par--;
                break;
        }
    }
    if (par != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
}