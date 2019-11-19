/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static int my_str_to_word_array_is_alphanum(char x)
{
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ||
            (x >= '0' && x <= '9'));
}

static void my_str_to_word_array_count_all(char const *str, int *inf)
{
    int i = 0;

    for (int x = 0; str[x] != '\0'; x++, i++) {
        if (!my_str_to_word_array_is_alphanum(str[x])) {
            inf[0]++;
            inf[1] = (inf[1] < i) ? i : inf[1];
            i = -1;
            for (; !my_str_to_word_array_is_alphanum(str[x]); x++);
            x--;
        }
    }
}

static char **my_str_to_word_array_clean_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (tab[i][0] == '\0') {
            free(tab[i]);
            for (int x = i; tab[x] != NULL; x++)
                tab[x] = tab[x + 1];
            i--;
        }
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int inf[2] = {0};
    my_str_to_word_array_count_all(str, inf);
    tab = malloc(sizeof(*tab) * (inf[0] + 2));
    for (int i = 0; i < inf[0] + 1; i++)
        tab[i] = malloc(sizeof(**tab) * (inf[1] + 2));
    for (int i = 0, x = 0, y = 0; str[i] != '\0'; i++, y++)
        if (my_str_to_word_array_is_alphanum(str[i]))
            tab[x][y] = str[i];
        else {
            y = -1;
            for (x = x + 1; !my_str_to_word_array_is_alphanum(str[i]) &&
                str[i] != '\0'; i++);
            i--;
        }
    tab[inf[0] + 1] = NULL;
    return (my_str_to_word_array_clean_array(tab));
}
