/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** my
*/

#pragma once

#include <stdio.h>
#include <drawing.h>
#include <stdlib.h>
#include <bitmap.h>

int fractal(int *data, uint32_t **img, int maxlvl);
void print_number(int *nbr, uint32_t **img);
int is_number(char *c);
int my_getnbr(char *str);