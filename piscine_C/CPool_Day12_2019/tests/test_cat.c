/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** test_cat
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <criterion/redirect.h>

int cat(char *const file);

void redirect(void)
{
    cr_redirect_stdout();
    system("echo \"Bonjour je m'appelle vincent, et je sait test\" > testfile");
}

void del_file(void)
{
    system("rm testfile");
}

Test(cat, testvalid, .init=redirect, .fini=del_file)
{
    cr_assert_eq(cat("testfile"), 0);
    cr_assert_stdout_eq_str("Bonjour je m'appelle vincent, et je sait test\n");
}

Test(cat, invalid)
{
    cr_assert_eq(cat("nofile"), 84);
}