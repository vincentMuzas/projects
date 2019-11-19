/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** tests_my_put_nbr
*/

int	my_put_nbr(int nb);
void my_putchar(char c);

int main(void)
{
    my_put_nbr(10);
    my_putchar('\n');
    my_put_nbr(-10);
    my_putchar('\n');
    my_put_nbr(0);
    my_putchar('\n');
    my_put_nbr(200);
    my_putchar('\n');
    my_put_nbr(-2147483647);
    my_putchar('\n');
    my_put_nbr(-2147483648);
    my_putchar('\n');
    return 0;
}
