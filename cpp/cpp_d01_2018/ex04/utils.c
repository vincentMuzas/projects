/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** utils
*/

int is_number(char *c)
{
    int i = 0;

    while (c[i] != 0){
        if (c[i] < '0' || c[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int my_getnbr(char *str)
{
    int i = 0, j = 1, nbr = 0;

    while (str[i] != 0)
        i++;
    i--;
    while (i >= 0){
        if (str[i] >= '0' && str[i] <= '9') {
            nbr += (str[i] - '0') * j;
            i --;
            j *= 10;
        }
        else
            return (0);
    }
    return (nbr);
}
