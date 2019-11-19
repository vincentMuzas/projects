/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>

int my_str_isnum(char *str);

Test(my_str_isnum, test1)
{
    cr_assert_eq(my_str_isnum("0123456789"), 1);
    cr_assert_eq(my_str_isnum("a0123456789"), 0);
    cr_assert_eq(my_str_isnum("0123456789z"), 0);
    cr_assert_eq(my_str_isnum("test"), 0);
}