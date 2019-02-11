/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** new function
*/

#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "raise.h"

void *new(Class *class, ...)
{
    Object *new_class;
    va_list argv;

    if (class == NULL)
        raise("Out of memory");
    new_class = malloc(class->__size__);
    if (new_class == NULL)
        raise("Out of memory");
    new_class = memcpy(new_class, class, class->__size__);
    va_start(argv, *class);
    ((Class *)new_class)->__ctor__(new_class, &argv);
    return (new_class);
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Out of memory");
    else {
        ((Class *)ptr)->__dtor__(ptr);
        free(ptr);
    }
}

Object *va_new(Class *class, va_list *ap)
{
    Object *obj;

    if (class == NULL)
        raise("Out of memory");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Out of memory");
    obj = memcpy(obj, class, class->__size__);
    ((Class *)obj)->__ctor__(obj, ap);
    return (obj);
}