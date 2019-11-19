/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, const char *src)
{
    for (int i = 0;; i++) {
        if (src[i] == '\0') {
            dest[i] = src[i];
            break;
        }
        dest[i] = src[i];
    }
    return (dest);
}
