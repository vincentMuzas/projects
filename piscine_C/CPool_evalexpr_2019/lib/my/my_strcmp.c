/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == 0)
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}