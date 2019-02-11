/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** ex02
*/

#include "string.h"
#include "d03.h"
#include <stdlib.h>
#include <string.h>

void append_s(string_t *this, const string_t *ap)
{
    if (ap->str == NULL)
        return;
    this->str = realloc(this->str, (len(this->str) +
                                    len(ap->str) + 1) * sizeof(char));
    cpy(&this->str[len(this->str)], ap->str);
}

void append_c(string_t *this, const char *ap)
{
    if (ap == NULL)
        return;
    this->str = realloc(this->str, (len(this->str) +
                                    len(ap) + 1) * sizeof(char));
    cpy(&this->str[len(this->str)], ap);
}