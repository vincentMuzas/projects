/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_strstr
*/

#include <criterion/criterion.h>

char *my_strstr(char *, char *);

Test(my_strstr, test01)
{
    char str[] = "Test42";

    cr_assert_str_eq(my_strstr(str, "42"), "42");
    cr_assert_str_eq(my_strstr(str, "t4"), "t42");
    cr_assert_eq(my_strstr(str, "oui"), NULL);
}