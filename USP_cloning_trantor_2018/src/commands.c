/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** commands
*/

#include "trantor.h"

char * forward(trantor_t *data) {
    switch (data->drone->orientation) {
        case 0:
            data->drone->y--;
            break;
        case 1:
            data->drone->x++;
            break;
        case 2:
            data->drone->y++;
            break;
        case 3:
            data->drone->x--;
            break;
    }
    char *ret = malloc(sizeof(char) * 4);
    strcpy(ret, "ok\n");
    return (ret);
}

char *left(trantor_t *data) {
    data->drone->orientation = (data->drone->orientation + 1) % 4;
    char *ret = malloc(sizeof(char) * 4);
    strcpy(ret, "ok\n");
    return (ret);
}

char *right(trantor_t *data) {
    data->drone->orientation = (data->drone->orientation - 1) % 4;
    char *ret = malloc(sizeof(char) * 4);
    strcpy(ret, "ok\n");
    return (ret);
}

char *parse_cmd_args(char *str, trantor_t *data) {
	char *cmd_wargs[] = {"take ", "drop ", NULL};
    char *(*func_wargs[])(trantor_t*, char *) = {take, drop};
    char *ret;

    for (int i = 0; cmd_wargs[i] != NULL && keepRunning; i++) {
        if (!strncmp(str, cmd_wargs[i], strlen(cmd_wargs[i]))) {
            pthread_mutex_lock(&data->mutex);
            ret = (func_wargs[i])(data, str);
            pthread_mutex_unlock(&data->mutex);
            return (ret);
        }
    }
    ret = malloc(sizeof(char) * 4);
    strcpy(ret, "ko\n");
    return (ret);
}

char *parse_cmd(char *str, trantor_t *data) {
    char *cmd_noargs[] = {"forward", "right", "left", "look", "inventory",NULL};
    char *(*func_noargs[])(trantor_t*) ={forward, right, left, look, inventory};
    char *ret;

    for (int i = 0; cmd_noargs[i] != NULL && keepRunning; i++) {
        if (!strcmp(cmd_noargs[i], str)) {
            pthread_mutex_lock(&data->mutex);
            ret = (func_noargs[i])(data);
            pthread_mutex_unlock(&data->mutex);
            return (ret);
        }
    }
    return (parse_cmd_args(str, data));
}