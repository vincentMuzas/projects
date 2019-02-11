/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** ex03
*/

#include "string.h"
#include "d03.h"
#include <stdlib.h>

char at(const string_t *this, size_t pos)
{
    if (this->str == NULL)
        return (-1);
    if (pos < (unsigned int)len(this->str))
        return (this->str[pos]);
    return (-1);
}