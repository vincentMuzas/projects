/*
** EPITECH PROJECT, 2018
** philo
** File description:
** c file
*/

#include "philo.h"

void print_help(char *name)
{
	printf("USAGE\n\t%s -p nbr_p -e nbr_e\n\nDESCRIPTION\n", name);
	printf("\t-p nbr_p number of philosophers\n");
	printf("\t-e nbr_e maximum number times a philosopher eats before");
	printf(" exiting the program\n");
}

int check_args(char **ac)
{
	if (strcmp(ac[1], "-p") == 0 && strcmp(ac[3], "-e") == 0);
	else if (strcmp(ac[1], "-e") == 0 && strcmp(ac[3], "-p") == 0);
	else
		return (1);
	for (size_t i = 0; i != strlen(ac[2]); i++)
		if (isdigit(ac[2][i]) == 0)
			return (1);
	for (size_t i = 0; i != strlen(ac[4]); i++)
		if (isdigit(ac[4][i]) == 0)
			return (1);
	if (atoi(ac[select_args("-p", ac)]) < 2)
		return (1);
	if (atoi(ac[select_args("-e", ac)]) == 0)
		return (0);
	return (0);
}

int select_args(char *arg, char **ac)
{
	if (strcmp(ac[1], arg) == 0)
		return (2);
	else
		return (4);
}

void create_philo(philo_t *philo, char **ac)
{
	philo->next = NULL;
	philo->eat = atoi(ac[select_args("-e", ac)]);
	philo->stat = EAT;
	philo->id = 0;
	philo->barrier = malloc(sizeof(*philo->barrier));
	pthread_barrier_init(philo->barrier, NULL,
		atoi(ac[select_args("-p", ac)]));
	pthread_mutex_init(&philo->mutex, NULL);
	for (size_t i = 0; i != atoi(ac[select_args("-p", ac)]) - 1; i++) {
		add_nex_philo(philo);
	}
}