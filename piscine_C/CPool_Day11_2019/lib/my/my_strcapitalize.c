/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strupcase
*/

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    char last = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && !is_alpha(last))
            str[i] -= 'a' - 'A';
        else if (str[i] >= 'A' && str[i] <= 'Z' && is_alpha(last))
            str[i] += 'a' - 'A';
        last = str[i];
    }
    return (str);
}