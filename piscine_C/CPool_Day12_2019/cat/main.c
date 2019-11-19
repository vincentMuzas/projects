/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** main
*/

int cat(char const *file);

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++) {
        cat(argv[i]);
    }
    return 0;
}
