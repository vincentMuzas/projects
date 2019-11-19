/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_strupcase
*/

#include <criterion/criterion.h>

char *my_strlowcase(char *);

Test(my_strlowcase, test1)
{
    char str1[] = "test bjr";
    char str2[] = "test Bjr";
    char str3[] = "TEsT bJr";
    cr_assert_str_eq(my_strlowcase(str1), "test bjr");
    cr_assert_str_eq(my_strlowcase(str2), "test bjr");
    cr_assert_str_eq(my_strlowcase(str3), "test bjr");
}