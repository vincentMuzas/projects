/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** float function
*/

#include <stdio.h>
#include <string.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    int tmp;

    tmp = strcmp(((Class *)this)->__name__, "Float");
    if (tmp == 0) {
        ((FloatClass *)this)->x = (float)va_arg(*args, double);
    }
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_String(Object *this)
{
    char *tmp;

    tmp = malloc(sizeof(char) * 30);
    sprintf(tmp, "<Float (%f)>", ((FloatClass *)this)->x);
    return (tmp);
}

static Object *Float_add(const Object *first, const Object *second)
{
    Object *new_object = new(Float, 0, 0);

    ((FloatClass *)new_object)->x = ((FloatClass *)first)->x + (
    (FloatClass*)second)->x;
    return new_object;
}

static Object *Float_sub(const Object *first, const Object *second)
{
    Object *new_object = new(Float, 0, 0);

    ((FloatClass *)new_object)->x = ((FloatClass *)first)->x - (
    (FloatClass*)second)->x;
    return new_object;
}

static Object *Float_mul(const Object *first, const Object *second)
{
    Object *new_object = new(Float, 0, 0);

    ((FloatClass *)new_object)->x = ((FloatClass *)first)->x * (
    (FloatClass*)second)->x;
    return new_object;
}

static Object *Float_div(const Object *first, const Object *second)
{
    Object *new_object = new(Float, 0, 0);

    ((FloatClass *)new_object)->x = ((FloatClass *)first)->x / (
    (FloatClass *)second)->x;
    return new_object;
}

static bool Float_eq(const Object *first, const Object *second)
{
    if (((FloatClass *)first)->x == ((FloatClass *)second)->x)
        return true;
    return false;
}

static bool Float_gt(const Object *first, const Object *second)
{
    if (((FloatClass *)first)->x > ((FloatClass *)second)->x)
        return true;
    return false;
}

static bool Float_lt(const Object *first, const Object *second)
{
    if (((FloatClass *)first)->x < ((FloatClass *)second)->x)
        return true;
    return false;
}

static FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_String,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

Class   *Float = (Class *)&_description;