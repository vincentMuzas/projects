/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** truc
*/

#include "string.h"
#include "d03.h"
#include <stdlib.h>

void string_init(string_t *this, const char *s)
{
    this->str = malloc(sizeof(char) * (len(s) + 1));
    this->assign_c = assign_c;
    this->assign_s = assign_s;
    this->append_c = append_c;
    this->append_s = append_s;
    this->at = at;
    this->clear = clear;
    this->size = size;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->find_s = find_s;
    this->find_c = find_c;
    cpy(this->str, s);
}

void string_destroy(string_t *this)
{
    free(this->str);
}