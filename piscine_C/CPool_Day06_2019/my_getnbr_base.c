/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_getnbr_base
*/

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

int contains(char const c, char const *list)
{
    for (int i = 0; list[i] != 0; i++) {
        if (list[i] == c)
            return (1);
    }
    return (0);
}

int my_getnbr_base(char *const str, char *const base)
{
    int nbr = 0, mult = 1, sign = 1, i = 0, j, last, multi = my_strlen(base);
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    j = i;
    while (contains(str[j], base))
        j++;
    j--;
    while (j >= i) {
        last = nbr;
        for (int k = 0; k < multi; k++)
            if (str[j] == base[k])
                nbr += k * mult * sign;
        mult *= multi;
        if ((sign == -1 && nbr > last) || (sign == 1 && nbr < last))
            return (0);
        j--;
    }
    return ((int) nbr);
}