/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_str_isupper
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
    return (1);
}
