/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++);
    for (int x = 0; src[x] != '\0' && x != nb; x++)
        dest[i + x] = src[x];
    if (src[nb] != '\0')
        dest[i + nb] = '\0';
    return (dest);
}
