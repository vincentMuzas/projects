/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_evil_str
*/

char *my_evil_str(char *str)
{
    int f = -1, b = -1;
    char t;

    while (str[++b] != '\0');
    if (b == 0)
        return (str);
    while (++f != --b && f < b) {
        t = str[f];
        str[f] = str[b];
        str[b] = t;
    }
    return (str);
}