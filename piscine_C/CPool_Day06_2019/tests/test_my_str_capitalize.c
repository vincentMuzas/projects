/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_strupcase
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *);

Test(my_strcapitalize, test1)
{
    char str1[] = "test bjr";
    char str2[] = "test Bjr";
    char str3[] = "TEsT bJr";
    cr_assert_str_eq(my_strcapitalize(str1), "Test Bjr");
    cr_assert_str_eq(my_strcapitalize(str2), "Test Bjr");
    cr_assert_str_eq(my_strcapitalize(str3), "Test Bjr");
}