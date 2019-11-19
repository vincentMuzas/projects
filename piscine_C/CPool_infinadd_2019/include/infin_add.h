/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add
*/

#ifndef INFIN_ADD_H_
#define INFIN_ADD_H_

#include <stdlib.h>
#include <string.h>
#include "my.h"

#define MAX(a, b) (a >= b) ? a : b
#define ISNUM(c) (c >= '0' && c <= '9') ? 1 : 0

char *infin_add(char const *str1, char const *str2);
char *trim_spaces(char *str);

#endif /* !INFIN_ADD_H_ */
