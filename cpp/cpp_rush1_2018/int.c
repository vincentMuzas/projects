/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** int function
*/

#include <stdio.h>
#include "int.h"
#include <string.h>
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    int tmp;

    tmp = strcmp(((Class *)this)->__name__, "Int");
    if (tmp == 0) {
        ((IntClass *)this)->x = va_arg(*args, int);
    }
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_String(Object *this)
{
    char *tmp;

    tmp = malloc(sizeof(char) * 30);
    sprintf(tmp, "<Int (%d)>", ((IntClass *)this)->x);
    return (tmp);
}

static Object *Int_add(const Object *first, const Object *second)
{
    Object *new_object = new(Int, 0, 0);

    ((IntClass *)new_object)->x = ((IntClass *)first)->x + (
    (IntClass*)second)->x;
    return new_object;
}

static Object *Int_sub(const Object *first, const Object *second)
{
    Object *new_object = new(Int, 0, 0);

    ((IntClass *)new_object)->x = ((IntClass *)first)->x - (
    (IntClass*)second)->x;
    return new_object;
}

static Object *Int_mul(const Object *first, const Object *second)
{
    Object *new_object = new(Int, 0, 0);

    ((IntClass *)new_object)->x = ((IntClass *)first)->x * (
    (IntClass*)second)->x;
    return new_object;
}

static Object *Int_div(const Object *first, const Object *second)
{
    Object *new_object = new(Int, 0, 0);

    ((IntClass *)new_object)->x = ((IntClass *)first)->x / (
    (IntClass*)second)->x;
    return new_object;
}

static bool Int_eq(const Object *first, const Object *second)
{
    if (((IntClass *)first)->x == ((IntClass *)second)->x)
        return true;
    return false;
}

static bool Int_gt(const Object *first, const Object *second)
{
    if (((IntClass *)first)->x > ((IntClass *)second)->x)
        return true;
    return false;
}

static bool Int_lt(const Object *first, const Object *second)
{
    if (((IntClass *)first)->x < ((IntClass *)second)->x)
        return true;
    return false;
}

static IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_String,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

Class   *Int = (Class *)&_description;