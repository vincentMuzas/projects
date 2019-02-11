/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** vertex function
*/


#include <stdio.h>
#include "vertex.h"
#include <string.h>
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    int tmp;

    tmp = strcmp(((Class *)this)->__name__, "Vertex");
    if (tmp == 0) {
        ((VertexClass *)this)->x = va_arg(*args, int);
        ((VertexClass *)this)->y = va_arg(*args, int);
        ((VertexClass *)this)->z = va_arg(*args, int);
    }
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_String(Object *this)
{
    char *tmp;

    tmp = malloc(sizeof(char) * 30);
    sprintf(tmp, "<Vertex (%d , %d, %d)>",
    ((VertexClass *)this)->x, ((VertexClass *)this)->y,
    ((VertexClass *)this)->z);
    return (tmp);
}

static Object *Vertex_add(const Object *first, const Object *second)
{
    Object *new_object = new(Vertex, 0, 0, 0);

    ((VertexClass *)new_object)->x = ((VertexClass *)first)->x + (
    (VertexClass *)second)->x;
    ((VertexClass *)new_object)->y = ((VertexClass *)first)->y + (
    (VertexClass *)second)->y;
    ((VertexClass *)new_object)->z = ((VertexClass *)first)->z + (
    (VertexClass *)second)->z;
    return new_object;
}

static Object *Vertex_sub(const Object *first, const Object *second)
{
    Object *new_object = new(Vertex, 0, 0, 0);

    ((VertexClass *)new_object)->x = ((VertexClass *)first)->x - (
    (VertexClass *)second)->x;
    ((VertexClass *)new_object)->y = ((VertexClass *)first)->y - (
    (VertexClass *)second)->y;
    ((VertexClass *)new_object)->z = ((VertexClass *)first)->z - (
    (VertexClass *)second)->z;
    return new_object;
}

static Object *Vertex_mul(const Object *first, const Object *second)
{
    Object *new_object = new(Vertex, 0, 0, 0);

    ((VertexClass *)new_object)->x = ((VertexClass *)first)->x * (
    (VertexClass *)second)->x;
    ((VertexClass *)new_object)->y = ((VertexClass *)first)->y * (
    (VertexClass *)second)->y;
    ((VertexClass *)new_object)->z = ((VertexClass *)first)->z * (
    (VertexClass *)second)->z;
    return new_object;
}

static Object *Vertex_div(const Object *first, const Object *second)
{
    Object *new_object = new(Vertex, 0, 0, 0);

    ((VertexClass *)new_object)->x = ((VertexClass *)first)->x / (
    (VertexClass *)second)->x;
    ((VertexClass *)new_object)->y = ((VertexClass *)first)->y / (
    (VertexClass *)second)->y;
    ((VertexClass *)new_object)->z = ((VertexClass *)first)->z / (
    (VertexClass *)second)->z;
    return new_object;
}

static bool Vertex_eq(const Object *first, const Object *second)
{
    if (((VertexClass *)first)->x == ((VertexClass *)second)->x && (
    (VertexClass *)first)->y == ((VertexClass *)second)->y && (
    (VertexClass*)first)->z == ((VertexClass *)second)->z)
        return true;
    return false;
}

static bool Vertex_gt(const Object *first, const Object *second)
{
    if (((VertexClass *)first)->x > ((VertexClass *)second)->x && (
    (VertexClass *)first)->y > ((VertexClass *)second)->y && (
    (VertexClass*)first)->z > ((VertexClass *)second)->z)
        return true;
    return false;
}

static bool Vertex_lt(const Object *first, const Object *second)
{
    if (((VertexClass *)first)->x < ((VertexClass *)second)->x && (
    (VertexClass *)first)->y < ((VertexClass *)second)->y && (
    (VertexClass*)first)->z < ((VertexClass *)second)->z)
        return true;
    return false;
}

static VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_String,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

Class   *Vertex = (Class *)&_description;