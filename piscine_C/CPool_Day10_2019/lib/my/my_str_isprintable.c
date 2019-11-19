/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_str_isnum
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if ( str[i] >= 0x20 && str[i] <= 0x7e );
        else
            return (0);
    }
    return (1);
}