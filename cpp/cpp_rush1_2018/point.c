/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include <string.h>
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    int tmp;

    tmp = strcmp(((Class *)this)->__name__, "Point");
    if (tmp == 0) {
        ((PointClass *)this)->x = va_arg(*args, int);
        ((PointClass *)this)->y = va_arg(*args, int);
    }
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_String(Object *this)
{
    char *tmp;

    tmp = malloc(sizeof(char) * 30);
    sprintf(tmp, "<Point (%d , %d)>",
    ((PointClass *)this)->x, ((PointClass *)this)->y);
    return (tmp);
}

static Object *Point_add(const Object *first, const Object *second)
{
    Object *new_object = new(Point, 0, 0);

    ((PointClass *)new_object)->x = ((PointClass *)first)->x + (
    (PointClass*)second)->x;
    ((PointClass *)new_object)->y = ((PointClass *)first)->y + (
    (PointClass*)second)->y;
    return new_object;
}

static Object *Point_sub(const Object *first, const Object *second)
{
    Object *new_object = new(Point, 0, 0);

    ((PointClass *)new_object)->x = ((PointClass *)first)->x - (
    (PointClass*)second)->x;
    ((PointClass *)new_object)->y = ((PointClass *)first)->y - (
    (PointClass*)second)->y;
    return new_object;
}

static Object *Point_mul(const Object *first, const Object *second)
{
    Object *new_object = new(Point, 0, 0);

    ((PointClass *)new_object)->x = ((PointClass *)first)->x * (
    (PointClass*)second)->x;
    ((PointClass *)new_object)->y = ((PointClass *)first)->y * (
    (PointClass*)second)->y;
    return new_object;
}

static Object *Point_div(const Object *first, const Object *second)
{
    Object *new_object = new(Point, 0, 0);

    ((PointClass *)new_object)->x = ((PointClass *)first)->x / (
    (PointClass*)second)->x;
    ((PointClass *)new_object)->y = ((PointClass *)first)->y / (
    (PointClass*)second)->y;
    return new_object;
}

static bool Point_eq(const Object *first, const Object *second)
{
    if (((PointClass *)first)->x == ((PointClass *)second)->x &&
    ((PointClass *)first)->y == ((PointClass *)second)->y)
        return true;
    return false;
}

static bool Point_gt(const Object *first, const Object *second)
{
    if (((PointClass *)first)->x > ((PointClass *)second)->x &&
        ((PointClass *)first)->y > ((PointClass *)second)->y)
        return true;
    return false;
}

static bool Point_lt(const Object *first, const Object *second)
{
    if (((PointClass *)first)->x < ((PointClass *)second)->x &&
        ((PointClass *)first)->y < ((PointClass *)second)->y)
        return true;
    return false;
}

static PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_String,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = (binary_operator_t)&Point_mul,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = (binary_comparator_t)&Point_eq,
        .__gt__ = (binary_comparator_t)&Point_gt,
        .__lt__ = (binary_comparator_t)&Point_lt
    },
    .x = 0,
    .y = 0
};

Class   *Point = (Class *)&_description;
