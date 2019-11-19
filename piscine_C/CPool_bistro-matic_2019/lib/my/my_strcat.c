/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++);
    for (int x = 0;; x++) {
        dest[i + x] = src[x];
        if (src[x] == '\0') {
            dest[i + x] = src[x];
            break;
        }
    }
    return (dest);
}
