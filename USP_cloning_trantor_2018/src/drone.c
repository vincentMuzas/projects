/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** drone
*/

#include "trantor.h"

void free_drones(drone_t *drone) {
	drone_t *old;
	while (drone != NULL) {
		old = drone;
		free(drone->quantity);
		drone = old->next;
		free(old);
	}
}

drone_t *create_drone(size_t* size) {
    drone_t *drone;
    if ((drone = malloc(sizeof(drone_t))) == NULL)
        exit (84);
    drone->x = rand() % size[0];
    drone->y = rand() % size[1];
    drone->orientation = rand() % 4;
    if ((drone->quantity = malloc(sizeof(int))) == NULL)
        exit (84);
    drone->quantity[0] = 0;
    drone->next = NULL;
    drone->inventory[0] = 10;
    for (int i = 1; i < 7; i++)
        drone->inventory[i] = 0;
    return (drone);
}

void show_drones(drone_t *list) {
    for (int i = 0; list != NULL; i++) {
        printf("drone %d: x:%d y:%d\n", i, list->x, list->y);
        list = list->next;
    }
}

drone_t *add_new_drone(drone_t *list, size_t* size) {
    drone_t *start = list;
    if (list == NULL) {
        list = create_drone(size);
        return (list);
    }
    while (list->next != NULL)
        list = list->next;
    list->next = create_drone(size);
    return (start);
}

void *drone_routine(void *data)
{
    int error = 0;
    socklen_t len = sizeof(error);
    trantor_t arg_list = ((trantor_t *)data)[0];
    char *msg, *ret;
    write(arg_list.fd, "ok", 2);
    for (int i = 0; keepRunning; i++) {
        if (getsockopt(arg_list.fd, SOL_SOCKET, SO_ERROR, &error, &len) != 0)
            break;
        if (error != 0 || !(msg = my_gnl(arg_list.fd)))
            break;
        ret = parse_cmd(msg, data);
        if (i == 0)
            write(arg_list.fd, msg, strlen(msg));
        else
            write(arg_list.fd, ret, strlen(ret));
        free(msg);
        free(ret);
    }
    free(data);
    close(arg_list.fd);
    return (NULL);
}