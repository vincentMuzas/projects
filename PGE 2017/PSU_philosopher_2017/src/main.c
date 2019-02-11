/*
** EPITECH PROJECT, 2018
** philo
** File description:
** main.c
*/

#include "philo.h"

void *philo_routine(void *data)
{
	philo_t *philo = (philo_t *)data;

	pthread_barrier_wait(philo->barrier);
	while (philo->eat != 0) {
		if (philo->stat == SLEEP)
			philo_think(philo);
		else if (philo->stat == THINK)
			philo_eat(philo);
		else
			philo_sleep(philo);
	}
	return (NULL);
}

void create_thread(philo_t *philo)
{
	philo_t *tmp = philo;

	do {
		pthread_create(&tmp->thread, NULL, philo_routine, tmp);
		tmp = tmp->next;
	} while (tmp->next->id != 1);
}

void wait_philo(philo_t *philo)
{
	philo_t *tmp = philo;

	do {
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	} while (tmp->next->id != 1);
}

void free_space(philo_t *philo)
{
	philo_t *tmp = philo;

	while (tmp->next->id != 0)
		tmp = tmp->next;
	tmp->next = NULL;
	tmp = philo;
	free(philo->barrier);
	while (philo->next != NULL) {
		tmp = philo->next;
		free(philo);
		philo = tmp;
	}
}

int main(int av, char **ac)
{
	philo_t *philo = malloc(sizeof(philo_t));

	if (av == 2 && strcmp(ac[1], "--help") == 0)
		print_help(ac[0]);
	else if (av == 5 && check_args(ac) == 0) {
		RCFStartup(av, ac);
		create_philo(philo, ac);
		link_end(philo);
		create_thread(philo);
		wait_philo(philo);
		free_space(philo);
		RCFCleanup();
	} else {
		exit(84);
	}
	exit(0);
}
