/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int i;
    for (i = 0; str[i] != 0; i++);
    return (i);
}