/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_stcmp
*/

#include <criterion/criterion.h>

int my_strcmp(char *, char *);

Test(my_strcmp, test1)
{
    cr_assert_eq(my_strcmp("oui", "oui"), 0);
    cr_assert_lt(my_strcmp("ouep", "oui"), 0);
    cr_assert_gt(my_strcmp("oui", "ouep"), 0);
}