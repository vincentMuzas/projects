/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int i;
    int j;
    unsigned char a;
    unsigned len = 0;
    while (str[len])
        len++;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
    return (str);
}