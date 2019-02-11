/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** my_str_to_wordtab
*/

#include <stdlib.h>
#include <string.h>

int	is_alphanum(char c)
{
    if (c == ' ' || c == '\n'|| c == ';' || c == 0)
        return (0);
    else
        return (1);
}

char **mallouche(char *str)
{
    char **tab;

    if ((tab = malloc(sizeof(char *) * strlen(str))) == NULL)
        exit(84);
    if ((tab[0] = malloc(sizeof(char *) * strlen(str))) == NULL)
        exit(84);
    return (tab);
}

void clean(char **tab)
{
    int i = 0, j;

    while (tab[i] != NULL) {
        if (tab[i][0] == 0) {
	        j = i;
            while (tab[j] != NULL) {
                tab[j] = tab[j + 1];
                j++;
            }
    	}
        i++;
    }
}

void free_wordtab(char **wt) {
    for (int i = 0; wt[i] != NULL; i++) {
        free(wt[i]);
    }
    free(wt);
}

char **my_str_to_wordtab(char *str)
{
    char **tab;
    int i = 0, j = 0, k = 0;

    tab = mallouche(str);
    while (str[i] != 0 && str[i] != ';') {
        if (is_alphanum(str[i]) == 0) {
            tab[j++][k] = 0;
            k = 0;
            if ((tab[j] = malloc(sizeof(char *) * strlen(str))) == NULL)
                exit (84);
        }
        else {
            tab[j][k++] = str[i];
            tab[j][k] = 0;
        }
        i++;
    }
    tab[j + 1] = NULL;
    clean(tab);
    return (tab);
}
