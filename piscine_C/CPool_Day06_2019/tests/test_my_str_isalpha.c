/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_str_isalpha
*/

#include <criterion/criterion.h>

int my_str_isalpha(char *str);

Test(my_str_isalpha, test1)
{
    cr_assert_eq(my_str_isalpha("abcdeABCDE"), 1);
    cr_assert_eq(my_str_isalpha("je suis vincent"), 0);
}