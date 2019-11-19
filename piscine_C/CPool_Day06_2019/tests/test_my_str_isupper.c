/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_str_isupper
*/

#include <criterion/criterion.h>

int my_str_isupper(char *str);

Test(my_str_isupper, test1)
{
    char str[] = {'A', 'Z', 1, 'Q', 'X', 'D'};
    cr_assert_eq(my_str_isupper("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 1);
    cr_assert_eq(my_str_isupper("a"), 0);
    cr_assert_eq(my_str_isupper("z"), 0);
    cr_assert_eq(my_str_isupper(str), 0);
}