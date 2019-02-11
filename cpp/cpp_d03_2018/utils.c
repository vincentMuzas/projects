/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** utils
*/

int len(const char *str)
{
    int i = 0;

    while (str[i] != 0) {
        i++;
    }
    return (i);
}

char *cpy(char *dest, const char *src)
{
    for (int i = 0; src[i] != 0; i++) {
        dest[i] = src[i];
        dest[i + 1] = 0;
    }
    return (dest);
}