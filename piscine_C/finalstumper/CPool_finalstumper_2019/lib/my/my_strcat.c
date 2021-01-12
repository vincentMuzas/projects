/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i, j;
    for (i = 0; dest[i] != 0; i++);
    for (j = 0; src[j] != 0; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
