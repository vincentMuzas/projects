/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_rev_params
*/

int my_putstr(char *const str);

int main(int argc, char **argv)
{
    for (argc--; argc >= 0; argc --) {
        my_putstr(argv[argc]);
        my_putstr("\n");
    }
    return 0;
}
