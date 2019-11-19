/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr
*/

int	my_getnbr(char const *str)
{
    int nbr = 0, mult = 1, sign = 1, i = 0, j, last;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    j = i;
    while (str[j] >= '0' && str[j] <= '9')
        j++;
    j--;
    while (j >= i) {
        last = nbr;
        nbr += (str[j] - '0') * mult * sign;
        mult *= 10;
        if ((sign == -1 && nbr > last) || (sign == 1 && nbr < last))
            return (0);
        j--;
    }
    return ((int) nbr);
}
