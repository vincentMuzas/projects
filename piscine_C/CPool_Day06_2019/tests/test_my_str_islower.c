/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_str_islower
*/

#include <criterion/criterion.h>

int my_str_islower(char *str);

Test(my_str_islower, test1)
{
    cr_assert_eq(my_str_islower("abcdez"), 1);
    cr_assert_eq(my_str_islower("abcdez "), 0);
    cr_assert_eq(my_str_islower("AbCdE"), 0);
    cr_assert_eq(my_str_islower("ABCDE"), 0);
}