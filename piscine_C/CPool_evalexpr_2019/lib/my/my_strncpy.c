/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
        if (dest[i] == 0)
            break;
    }
    return (dest);
}