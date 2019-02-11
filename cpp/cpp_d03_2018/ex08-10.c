/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** ex08
*/

#include "string.h"
#include <string.h>
#include "d03.h"

const char *c_str(const string_t *this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    if (this == NULL || this->str == NULL || this->size(this) == 0)
        return (1);
    return (0);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int res;
    if (!this || !this->str || !str || !str->str)
        return (-1);
    if (pos > strlen(this->str))
        return (-1);
    res = strstr(&this->str[pos], str->str) - this->str;
    if (res < 0)
        return (-1);
    return (res);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int res;
    if (!this || !this->str || !str)
        return (-1);
    if (pos > strlen(this->str))
        return (-1);
    res = strstr(&this->str[pos], str) - this->str;
    if (res < 0)
        return (-1);
    return (res);
}