/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** main
*/

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>
              

void *first_instance(void *key_data)
{
	int shm_id;
	int sem_id;
	printf("penis\n");
	key_t *key = key_data;
	printf("instance key: %d\n", key[0]);

	shm_id = shmget(key[0], 2500 * sizeof(int), IPC_CREAT | SHM_R | SHM_W);
	printf("Created shm: %d\n", shm_id);
	sem_id = semget(key[0], 1, IPC_CREAT | SHM_R | SHM_W);
	printf("Created sem; %d\n", sem_id);
	semctl(shm_id, 0, SETVAL, 2500);
	shmdt(&shm_id);
	printf("Deleted shm: %d\n", shm_id);
	shmdt(&sem_id);
	printf("Deleted sem: %d\n", sem_id);
	pthread_exit(0);
}

pthread_t *create_thread(key_t key)
{
	pthread_t *thread;
	printf("penis\n");
	pthread_create(thread, NULL, first_instance, &key);
	return (thread);
}


void print_help_exit(char *name)
{
	printf("USAGE %s PATH TEAM_NUMBER\n\n", name);
	printf("DESCRIPTION\n");
	printf("\tPATH\t\tpath you'll give to ftok\n");
	printf("\tTEAM_NUMBER\tteam number of the current champion ");
	printf("(greater than 0)\n");
	exit(84);
}

void change_sem(int semid, int value)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = value;
	semop(semid, &sops, 1);
}

int main(int ac, char **av)
{
	key_t		key;
	int		shm_id;
	struct sembuf	sops;
	pthread_t *sub = NULL;

	if (ac != 3)
		print_help_exit(av[0]);
	key = ftok(av[1], 0);
	printf("Key : %d\n", key);

	shm_id = shmget(key, 1, SHM_R | SHM_W);
	if (shm_id == -1)
		sub = create_thread(key);
	if (sub != NULL)
		pthread_join(*sub, NULL);
}