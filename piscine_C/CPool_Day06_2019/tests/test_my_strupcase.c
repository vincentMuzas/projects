/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_strupcase
*/

#include <criterion/criterion.h>

char *my_strupcase(char *);

Test(my_strupcase, test1)
{
    char str1[] = "test bjr";
    char str2[] = "test Bjr";
    char str3[] = "tEsT bJr";
    cr_assert_str_eq(my_strupcase(str1), "TEST BJR");
    cr_assert_str_eq(my_strupcase(str2), "TEST BJR");
    cr_assert_str_eq(my_strupcase(str3), "TEST BJR");
}