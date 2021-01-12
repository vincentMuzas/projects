/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr
*/

void my_putchar(char);

int my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != 0)
    {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}