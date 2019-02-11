/*
** EPITECH PROJECT, 2018
** philo
** File description:
** c file
*/

#include "philo.h"

void add_nex_philo(philo_t *philo)
{
	philo_t *tmp = philo;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(philo_t));
	tmp->next->eat = tmp->eat;
	tmp->next->id = tmp->id + 1;
	tmp->next->barrier = tmp->barrier;
	tmp = tmp->next;
	tmp->next = NULL;
	tmp->stat = EAT;
	pthread_mutex_init(&tmp->mutex, NULL);
}

void link_end(philo_t *philo)
{
	philo_t *tmp = philo;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = philo;
}

void philo_think(philo_t *philo)
{
	pthread_mutex_t *mutex;
	while (1) {
		if (pthread_mutex_trylock(&philo->mutex) == 0) {
			lphilo_take_chopstick(&philo->mutex);
			mutex = &philo->mutex;
			break;
		} else if (pthread_mutex_trylock(&philo->next->mutex) == 0) {
			lphilo_take_chopstick(&philo->mutex);
			mutex = &philo->next->mutex;
			break;
		}
		usleep(10);
	}
	lphilo_think();
	usleep(100);
	philo->stat = THINK;
	pthread_mutex_unlock(mutex);
	lphilo_release_chopstick(mutex);
}

void philo_eat(philo_t *philo)
{
	if (pthread_mutex_trylock(&philo->mutex) == 0)
		usleep(10);
	lphilo_take_chopstick(&philo->mutex);
	if (pthread_mutex_trylock(&philo->next->mutex) == 0)
		usleep(10);
	lphilo_take_chopstick(&philo->next->mutex);
	lphilo_eat();
	philo->eat -= 1;
	usleep(100);
	philo->stat = EAT;
	pthread_mutex_unlock(&philo->mutex);
	lphilo_release_chopstick(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
	lphilo_release_chopstick(&philo->next->mutex);
}

void philo_sleep(philo_t *philo)
{
	lphilo_sleep();
	philo->stat = SLEEP;
}