/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** main
*/

void my_putchar(char);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);

int main(int av, char **ac)
{
    char *tmp;

    for (int i = 0; i < av - 1; i++)
        if (my_strcmp(ac[i], ac[i + 1]) > 0) {
            tmp = ac[i];
            ac[i] = ac[i + 1];
            ac[i + 1] = tmp;
            i = -1;
        }
    for (int i = 0; i != av; i++) {
        my_putstr(ac[i]);
        my_putchar('\n');
    }
}