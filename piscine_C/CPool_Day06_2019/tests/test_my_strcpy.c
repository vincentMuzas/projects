/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** test_my_strcpy
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char *src);

Test(my_strcpy, test1)
{
    char dest[7] = {0};
    my_strcpy(dest, "Jambon");
    cr_assert_str_eq(dest, "Jambon");

}