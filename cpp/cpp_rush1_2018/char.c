/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** char function
*/


#include <stdio.h>
#include <string.h>
#include "new.h"
#include "char.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    int tmp;

    tmp = strcmp(((Class *)this)->__name__, "Char");
    if (tmp == 0) {
        ((CharClass *)this)->x = (char)va_arg(*args, int);
    }
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_String(Object *this)
{
    char *tmp;

    tmp = malloc(sizeof(char) * 30);
    sprintf(tmp, "<Char (%c)>", ((CharClass *)this)->x);
    return (tmp);
}

static Object *Char_add(const Object *first, const Object *second)
{
    Object *new_object = new(Char, 0, 0);

    ((CharClass *)new_object)->x = ((CharClass *)first)->x + (
    (CharClass*)second)->x;
    return new_object;
}

static Object *Char_sub(const Object *first, const Object *second)
{
    Object *new_object = new(Char, 0, 0);

    ((CharClass *)new_object)->x = ((CharClass *)first)->x - (
    (CharClass*)second)->x;
    return new_object;
}

static Object *Char_mul(const Object *first, const Object *second)
{
    Object *new_object = new(Char, 0, 0);

    ((CharClass *)new_object)->x = ((CharClass *)first)->x * (
    (CharClass*)second)->x;
    return new_object;
}

static Object *Char_div(const Object *first, const Object *second)
{
    Object *new_object = new(Char, 0, 0);

    ((CharClass *)new_object)->x = ((CharClass *)first)->x / (
    (CharClass*)second)->x;
    return new_object;
}

static bool Char_eq(const Object *first, const Object *second)
{
    if (((CharClass *)first)->x == ((CharClass *)second)->x)
        return true;
    return false;
}

static bool Char_gt(const Object *first, const Object *second)
{
    if (((CharClass *)first)->x > ((CharClass *)second)->x)
        return true;
    return false;
}

static bool Char_lt(const Object *first, const Object *second)
{
    if (((CharClass *)first)->x < ((CharClass *)second)->x)
        return true;
    return false;
}

static CharClass _description = {
{
.__size__ = sizeof(CharClass),
.__name__ = "Char",
.__ctor__ = (ctor_t)&Char_ctor,
.__dtor__ = (dtor_t)&Char_dtor,
.__str__ = (to_string_t)&Char_String,
.__add__ = (binary_operator_t)&Char_add,
.__sub__ = (binary_operator_t)&Char_sub,
.__mul__ = (binary_operator_t)&Char_mul,
.__div__ = (binary_operator_t)&Char_div,
.__eq__ = (binary_comparator_t)&Char_eq,
.__gt__ = (binary_comparator_t)&Char_gt,
.__lt__ = (binary_comparator_t)&Char_lt
},
.x = 0
};

Class   *Char = (Class *)&_description;

#include "char.h"
