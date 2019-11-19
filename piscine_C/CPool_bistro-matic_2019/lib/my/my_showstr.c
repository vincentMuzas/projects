/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_showstr
*/

void my_putchar(char);

static void my_showstr_print_hex(int nb)
{
    int tab[2] = {0};
    char str[16] = "0123456789abcdef";

    tab[1] = nb % 16;
    if (nb > 15) {
        nb -= 16;
        nb /= 16;
        tab[2] = nb % 16;
    }
    my_putchar('\\');
    my_putchar(str[tab[0]]);
    my_putchar(str[tab[1]]);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else
            my_showstr_print_hex(str[i]);
    return (0);
}
