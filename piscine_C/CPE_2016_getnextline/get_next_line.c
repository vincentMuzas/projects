/*
** main.c for  in /home/vincent/Documents/CPE_2016_getnextline
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 17:21:16 2017 vincent
** Last update Sun Jan 15 19:52:01 2017 vincent
*/

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void my_strcpy(char *str, char *dest)
{
    int i = 0;
    while (str[i] != 0) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = 0;
}

char *get_next_line(const int fd)
{
    char *str, *buffer;
    int count[2];
    int res;
    str = malloc(sizeof(char) * READ_SIZE + 1);
    buffer = malloc(sizeof(char) * 4096);
    while ((res = read(fd, str, READ_SIZE)) > 0) {
        my_strcpy(str, &buffer[count[0] * READ_SIZE]);
        while (buffer[count[1]] != '\0') {
            if (buffer[count[1]] == '\n') {
                buffer[count[1]] = 0;
                return (buffer);
            }
            count[1]++;
        }
        count[0]++;
    }
    return (NULL);
}
