/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_mystrncpy
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, test1)
{
    char dest[6] = {0};
    my_strncpy(dest, "Jambon", 5);
    cr_assert_str_eq(dest, "Jambo");
}