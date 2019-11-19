/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strstr
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int j;
    while (str[0] != 0) {
        j = 0;
        while (str[j] == to_find[j] || to_find[j] == 0) {
            if (to_find[j] == 0)
                return (str);
            j++;
        }
        str++;
    }
    return (NULL);
}