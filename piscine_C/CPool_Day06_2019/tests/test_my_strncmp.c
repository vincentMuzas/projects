/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_stcmp
*/

#include <criterion/criterion.h>

int my_strncmp(char *, char *, int);

Test(my_strncmp, test1)
{
    cr_assert_eq(my_strncmp("oui", "oua", 2), 0);
    cr_assert_eq(my_strncmp("ouep", "oui", 2), 0);
    cr_assert_neq(my_strncmp("oui", "oue", 3), 0);
    cr_assert_gt(my_strncmp("oui", "ouep", 3), 0);
}