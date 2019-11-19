/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** test_grep
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <grep.h>
#include <stdlib.h>

Test(my_strstr, test01)
{
    char str[] = "abcd";
    cr_assert_eq(my_strstr(str, "cd"), (&str[2]));
    cr_assert_eq(my_strstr(str, "bd"), NULL);
}

void ini_gnl(void)
{
    cr_redirect_stdout();
    system("echo \"l1\nl2\nl3\nl4\" > testfile");
}

void fini_gnl(void)
{
    system("rm testfile");
}

Test(my_gnl, test02, .init=ini_gnl, .fini=fini_gnl)
{
    int fd = open("testfile", O_RDONLY);
    char *str = my_gnl(fd);
    cr_assert_str_eq("l1", str);
    free(str);
    str = my_gnl(fd);
    cr_assert_str_eq("l2", str);
    free(str);
    str = my_gnl(fd);
    cr_assert_str_eq("l3", str);
    free(str);
    str = my_gnl(fd);
    cr_assert_str_eq("l4", str);
    free(str);
    str = my_gnl(fd);
    cr_assert_eq(NULL, str);
    free(str);
}

int my_strlen(char *str);

Test(my_strlen, test03)
{
    char str[] = "bonjour";
    cr_assert_eq(my_strlen(str), 7);
}

Test(grep, test04, .init=ini_gnl, .fini=fini_gnl)
{
    
}