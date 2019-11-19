/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_revstr
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, test1)
{
    char str[10] = {0}, str2[10] = {0}, str3[1] = {0};
    strcpy(str, "fedcba");
    strcpy(str2, "gfedcba");
    my_revstr(str);
    my_revstr(str2);
    my_revstr(str3);

    cr_assert_str_eq(str, "abcdef");
    cr_assert_str_eq(str2, "abcdefg");
    cr_assert_str_eq(str3, "");
    cr_assert_eq(my_revstr(str), str);
}