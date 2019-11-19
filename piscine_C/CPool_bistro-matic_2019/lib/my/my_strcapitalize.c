/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z' &&
                (i == 0 || !((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
                (str[i - 1] >= 'A' && str[i - 1] <= 'Z'))))
            str[i] -= 32;
        else if (str[i] <= 'Z' && str[i] >= 'A' &&
                (i != 0 && ((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
                (str[i - 1] >= 'A' && str[i - 1] <= 'Z'))))
            str[i] += 32;
    return (str);
}
