/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** ex04
*/

#include "string.h"
#include "d03.h"
#include <stdlib.h>
#include <string.h>

void clear(string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    this->str[0] = 0;
}

int size(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return (-1);
    return (len(this->str));
}

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || this->str == NULL || str == NULL || str->str == NULL)
        return (0);
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || this->str == NULL || str == NULL)
        return (0);
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    if (s == NULL || this == NULL)
        return (0);
    return ((size_t)strncpy(&this->str[pos], s, n));
}