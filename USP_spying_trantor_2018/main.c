/*
** EPITECH PROJECT, 2018
** spying_trantor
** File description:
** main.c
*/

#include "spying_trantor.h"

int main(int ac, char ** av)
{
	int socket_desc, fd = 0;
	struct sockaddr_in sin = {0};
	char server_reply[2000] = {0};
	args_t args = init_args(ac, av);
	if (args.validator || ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == -1))
		return (84);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(atoi(args.port));
	sin.sin_addr.s_addr = inet_addr(args.ip);
	if ((connect(socket_desc, (const struct sockaddr*)&sin, sizeof(sin)) == -1) ||
			(ac == 5 && (fd = open(av[4], O_RDONLY)) < 0))
		return (84);
	write(socket_desc, args.squad, strlen(args.squad) * sizeof(char));
	read(socket_desc, &server_reply, 2000);
	read(socket_desc, &server_reply, 2000);
	if (strncmp(server_reply, "ko", 2) == 0)
			return (84);
	printf("connected to a drone from %s on port %s\n", av[3],args.port);
	loop(socket_desc, fd);
	return (0);
}

void loop(int socket_desc, int fd)
{
	char *message, server_reply[2000], validator;
	while (1) {
		memset(server_reply, 0, 2000);
		printf("$> ");
		fflush(stdout);
		message = my_gnl(fd);
		if (message == NULL)
			break;
		validator = parse(message);
		if (fd != 0)
			printf("%s", message);
/*		if (validator == 0) {
			free (message);
			printf("invalid command\n");
			continue;
		}*/
		write(socket_desc, message, strlen(message) * sizeof(char));
		free(message);
		read(socket_desc, &server_reply, 2000);
		printf("%s", server_reply);
	}
}

int parse(char *message)
{
	char *cmd_list[5] = {"forward\n", "right\n", "left\n", 
		"look\n", "inventory\n"};
	char *keywords[2] = {"take", "drop"};
	int i = 0;

	while (i < 5) {
		if (strcmp(cmd_list[i], message) == 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 2) {
		if (strncmp(keywords[i], message, strlen(keywords[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

args_t init_args(int ac, char **av)
{
	args_t reponse;

	reponse.validator = 0;
	if (ac != 4 && ac != 5) {
		reponse.validator = -1;
		print_help(av[0]);
		return (reponse);
	}
	reponse.ip = av[1];
	if (!is_Valid_Ip_Address(reponse.ip))
		reponse.validator = -1;
	reponse.port = av[2];
	if (!str_is_digit(reponse.port))
		reponse.validator = -1;
	reponse.squad = malloc(sizeof(char) * strlen(av[3]) + 1);
	strcpy(reponse.squad, av[3]);
	reponse.squad = append_char(reponse.squad, '\n');
	if (reponse.validator == -1)
		print_help(av[0]);
	return (reponse);
}