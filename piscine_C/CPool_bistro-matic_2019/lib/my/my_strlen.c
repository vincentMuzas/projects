/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int res = -1;

    while (str[++res] != '\0');
    return (res);
}
