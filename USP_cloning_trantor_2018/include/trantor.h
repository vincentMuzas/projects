/*
** EPITECH PROJECT, 2018
** spying_trantor
** File description:
** trantor.h
*/

#ifndef TRANTOR_H_
    #define TRANTOR_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <signal.h>
#include <poll.h>

extern int keepRunning;
extern int listen_port;

typedef struct args_s {
    size_t size[2];
    char *port;
    int error;
}   args_t;

typedef struct drone_s drone_t;
struct drone_s {
    int x;
    int y;
    int *quantity;
    int orientation;
    int inventory[7];
    drone_t *next;
};

typedef struct map_s {
    char **resource;
    int quantity;
} map_t;

typedef struct trantor_s {
    int fd;
    struct sockaddr address;
    map_t **map;
    size_t *size;
    drone_t *drone;
    drone_t *drone_list;
    pthread_mutex_t mutex;
} trantor_t;

typedef struct serv_loop_s {
    map_t **map;
    int sockfd;
    drone_t *drone_list;
    args_t arg_list;
    pthread_t *thread_list;
    pthread_mutex_t mutex;
    int thread_count;
    int len;
} serv_loop_t;

/* int_handler.c */
void intHandler(int dummy);

/* gnl.c */
char *my_gnl(int fd);
char *append_char(char *str, char c);

/* utils.c */
args_t args(char **av);
int helper(int ac, char **av);
int str_is_digit(char *str);
char *getArg(char **av, int ac, char *what);

/*
** map.c
*/
map_t **create_map(int width, int height);
void draw_map(map_t** map, size_t *size, drone_t *drone);
void free_map(map_t** map, size_t *size);

/*
** drone.c
*/
void free_drones(drone_t *drone);
drone_t *add_new_drone(drone_t *list, size_t* size);
void show_drones(drone_t *list);
drone_t *create_drone(size_t* size);
void *drone_routine(void *data);

/* commands.c */
char *parse_cmd(char *str, trantor_t *data);

/* look.c */
char *look(trantor_t *data);

/* look_utils.c */
char *str_clean(char *str);
char *getpos_content(trantor_t *data, size_t x, size_t y);

/* inventory.c */
char *inventory(trantor_t *data);

/* my_str_to_wordtab.c */
char **my_str_to_wordtab(char *str);
void free_wordtab(char **wt);

/* drop.c */
char *drop(trantor_t *data, char *msg);

/* take.c */
char *take(trantor_t *data, char *cmd);

#endif /* !TRANTOR_H_ */
