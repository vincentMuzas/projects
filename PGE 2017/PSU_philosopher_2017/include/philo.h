/*
** EPITECH PROJECT, 2018
** philo
** File description:
** header file
*/

#ifndef PHILO_H_
# define PHILO_H_

# include "extern.h"
# include "pthread.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

enum {
	SLEEP,
	EAT,
	THINK,
};

typedef struct philo_s {
	pthread_barrier_t *barrier;
	pthread_t thread;
	pthread_mutex_t mutex;
	struct philo_s *next;
	size_t eat;
	size_t stat;
	size_t id;
} philo_t;

void add_nex_philo(philo_t *philo);
void link_end(philo_t *philo);
void philo_think(philo_t *philo);
void philo_eat(philo_t *philo);
void philo_sleep(philo_t *philo);
void print_help(char *name);
int check_args(char **ac);
int select_args(char *arg, char **ac);
void create_philo(philo_t *philo, char **ac);

#endif /* !PHILO_H_ */
