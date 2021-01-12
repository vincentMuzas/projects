/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** my_epur_str
*/

void my_epur_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ' || str[i] == '\t')
            for (int x = i--; str[x] != '\0'; x++)
                str[x] = str[x + 1];
}
