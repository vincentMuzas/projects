/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_str_isprintable
*/

#include <criterion/criterion.h>

int my_str_isprintable(char *str);

Test(my_str_isprintable, test1)
{
    char str[] = {'a', 'b', 1, 'a', 'a', 'a'};
    cr_assert_eq(my_str_isprintable("0123456789"), 1);
    cr_assert_eq(my_str_isprintable("a0123456789"), 1);
    cr_assert_eq(my_str_isprintable("0123456789z"), 1);
    cr_assert_eq(my_str_isprintable(str), 0);
}