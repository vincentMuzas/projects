/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= '0' && str[i] <= '9');
        else
            return (0);
    }
    return (1);
}