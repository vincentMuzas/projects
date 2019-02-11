/*
** EPITECH PROJECT, 2019
** cpp_d02m_2018
** File description:
** add_mul
*/

#include <stdio.h>

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int f = *first, s = *second;

    *first = f + s;
    *second = f * s;
}