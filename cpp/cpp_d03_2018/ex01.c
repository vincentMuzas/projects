/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** ex01
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

void assign_s(string_t *this, const string_t *str)
{
    if (this->str == NULL || str->str == NULL)
        return;
    if (len(this->str) < len(str->str)) {
        if ((this = realloc(this, sizeof(char) * (len(str->str) + 1))))
            return;
    }
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str == NULL || s == NULL)
        return;
    if (len(this->str) < len(s)) {
        if ((this = realloc(this, sizeof(char) * (len(s) + 1))))
            return;
    }
    strcpy(this->str, s);
}