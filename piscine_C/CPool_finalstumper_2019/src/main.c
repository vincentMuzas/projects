/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** main
*/

#include "my.h"
#include "rush3.h"

liste_t *get_content()
{
    liste_t *liste, *start;
    liste = malloc(sizeof(liste_t));
    start = liste;
    while (liste != NULL) {
        liste->str = my_gnl(0);
        if ((liste->next = malloc(sizeof(liste_t))) == NULL)
            return (NULL);
        if (liste->str == NULL)
            break;
        liste = liste->next;
    }
    return (start);
}

void free_list(liste_t *list)
{
    void *ptr = list;
    if (list == NULL)
        return;
    while (list->str != NULL) {
        free(list->str);
        ptr = list;
        list = list->next;
        free(ptr);
    }
}

int errors(liste_t *liste) {
    if (liste == NULL || liste->str == NULL) {
      my_putstr("none\n");
          return (1);
    }
    for (int size = my_strlen(liste->str);
	 liste->str != NULL; liste = liste->next) {
        if (size != my_strlen(liste->str)) {
            my_putstr("none\n");
            return (1);
        }
    }
    return (0);
}

int main()
{
    int (*fnt[])(liste_t*) = {&detect1, &detect2,
			      &detect3, &detect4, &detect5};
    char *str[] = {"[rush1-1]", "[rush1-2]",
		   "[rush1-3]", "[rush1-4]", "[rush1-5]"};
    liste_t *liste;
    int found = 0;
    if (errors((liste = get_content())))
        return (0);
    else for (int i = 0; i < 5; i++)
	if (fnt[i](liste)) {
            if (found)
                my_putstr(" | ");
            my_putstr(str[i]);
            size(liste);
	    found = 1;
        }
    if (!found)
        my_putstr("none");
    my_putchar('\n');
    free_list(liste);
    return (0);
}
