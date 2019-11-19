/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr
*/

static int check_extrem(char const *str)
{
    char max_int[2][12] = {"2147483647", "-2147483648"};
    int b = 0;

    if (str[0] == '-')
        b = 1;
    for (int i = 0; str[i + b] != '\0' && str[i + b] >= '0' &&
            str[i + b] <= '9'; i++)
        if (str[i + b] > max_int[b][i + b])
            return (1);
    return (0);
}

static int nbr_len(char const *str)
{
    int i = -1;

    while (str[++i] >= '0' && str[i] <= '9');
    if (i < 10)
        return (0);
    else if (i == 10)
        return (2);
    return (1);
}

static int check_nbr(char const *str)
{
    int s = 0, chk = 0;

    if (str[0] == '-')
        s = 1;
    chk = nbr_len(&str[s]);
    if (chk == 2)
        return (check_extrem(str));
    return (chk);
}

int my_getnbr(char const *str)
{
    int i = -1, res = 0, n = 0;

    while (str[++i] != '\0' && !(str[i] >= '0' && str[i] <= '9') &&
        !(str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')));
    if (str[i] == '\0' || check_nbr(&str[i]))
        return (res);
    if (nbr_len((str[i] == '-') ? &str[i + 1] : &str[i]) == 2)
        return ((str[i] == '-') ? -2147483648 : 2147483647);
    n = (str[i] == '-') ? 1 : 0;
    while (str[i + n] >= '0' && str[i + n] <= '9') {
        res *= 10;
        res += (str[i + n] - 48);
        i++;
    }
    return ((n == 1) ? (res * -1) : res);
}
