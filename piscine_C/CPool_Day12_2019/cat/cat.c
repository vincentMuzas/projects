/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int cat(char const *file)
{
    int fd = open(file, O_RDONLY);
    char str[16];
    int readed;
    if (fd < 0)
        return (84);
    while ((readed = read(fd, str, 16)) > 0) {
        write(1, str, readed);
    }
    return (0);
}