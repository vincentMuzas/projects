/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** grep
*/

#ifndef GREP_H_
#define GREP_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *my_strstr(char *str, char const *to_find);
char *my_gnl(int fd);
int grep(char const* search, char const* file);

#endif /* !GREP_H_ */
