/*
** EPITECH PROJECT, 2018
** spying_trantor
** File description:
** header
*/

#ifndef SPYING_TRANTOR_H
#define SPYING_TRANTOR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>

#define closesocket(s) close(s)
#define GET 0
#define SET 1
typedef struct args_s
{
	int validator;
	char *ip;
	char *port;
	char *squad;
} args_t;


/*
 * main.c
 */

void loop(int socket_desc, int fd);
int parse(char *message);
args_t init_args(int ac, char **av);

/*
 * utils.c
 */

int is_Valid_Ip_Address(char *ipAddress);
int str_is_digit(char *str);
void print_help(char *name);

/*
 * gnl.c
 */

char *my_gnl(int fd);
char *append_char(char *str, char c);


#endif /* !SPYING_TRANTOR_H */