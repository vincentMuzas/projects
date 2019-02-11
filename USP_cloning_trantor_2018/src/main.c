/*
** EPITECH PROJECT, 2018
** spying_trantor
** File description:
** main
*/

#include "trantor.h"

void cpy_trantor(trantor_t *dest, serv_loop_t *src) {
    dest->map = src->map;
    dest->size = src->arg_list.size;
    dest->drone_list = src->drone_list;
    dest->mutex = src->mutex;
}

struct sockaddr_in create_sin(char *port) {
    struct sockaddr_in sin = {0};
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(port));
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(&(sin.sin_zero), 8);
    return (sin);
}

void server_loop(serv_loop_t *arg)
{
    drone_t *drone;
    trantor_t *client;
    if ((client = malloc(sizeof(trantor_t))) == NULL)
        exit (84);
    if ((client->fd = accept(arg->sockfd,
        (struct sockaddr *)&client[0].address, (socklen_t*)&arg->len)) < 0)
        return;
    arg->drone_list = add_new_drone(arg->drone_list, arg->arg_list.size);
    drone = arg->drone_list;
    while (drone != NULL && drone->next != NULL)
        drone = drone->next;
    cpy_trantor(client, arg);
    client->drone = drone;
    if ((arg->thread_list = realloc(arg->thread_list, sizeof(pthread_t)
                                * (arg->thread_count + 1))) == NULL)
        exit (84);
    if (pthread_create(&arg->thread_list[arg->thread_count], NULL,
        drone_routine, &client[0]) != 0)
        shutdown(client[0].fd, SHUT_RDWR);
}

void init_loop_args(serv_loop_t *var, size_t *size) {
    var->drone_list = NULL;
    var->thread_count = 0;
    if ((var->thread_list = malloc(sizeof(pthread_t))) == NULL)
        exit (84);
    var->map = create_map(size[0], size[1]);
    if ((var->sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit (84);
    if (setsockopt(var->sockfd,SOL_SOCKET,SO_REUSEADDR,&(int){1},sizeof(int))<0)
        exit (84);
    var->len = sizeof(struct sockaddr_in);
    var->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
}

int main(int ac, char **av)
{
    struct sockaddr_in sin = {0};
    serv_loop_t loop_args;
    if (helper(ac, av) != 0 || ac != 7 || (loop_args.arg_list = args(av)).error)
        return (84);
    init_loop_args(&loop_args, loop_args.arg_list.size);
    sin = create_sin(loop_args.arg_list.port);
    if (bind(loop_args.sockfd, (const struct sockaddr *)&sin, sizeof(sin))==-1)
        return (84);
    if (listen(loop_args.sockfd, 100) < 0)
        return (84);
    signal(SIGINT, intHandler);
    while (keepRunning) {
        server_loop(&loop_args);
        loop_args.thread_count ++;
    }
    for (int i = 0; i < loop_args.thread_count; i++)
        pthread_join(loop_args.thread_list[i], NULL);
    free(loop_args.thread_list);
    free_map(loop_args.map, loop_args.arg_list.size);
    free_drones(loop_args.drone_list);
    return (0);
}