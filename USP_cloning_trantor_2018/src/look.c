/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** look
*/

#include "trantor.h"

char *look_right(trantor_t *data) {
    int x = data->drone->x % data->size[0],y=data->drone->y%data->size[1],count;
    char *loc, *ret = malloc(sizeof(char) * 2);
    strcpy(ret, "[");
    for (int i = 0; i < 4; i++) {
        count = 0;
        do {
            loc = getpos_content(data, x, y);
            if((ret = realloc(ret, sizeof(char) *
                (strlen(ret) + strlen(loc) + 5))) == NULL)
                exit(84);
            ret = strcat(ret, loc);
            ret = strcat(ret, " ,");
            free(loc);
            count ++;
            y ++;
        } while (count != 1 + 2 * i);
        y = data->drone->y - i - 1;
        x++;
    }
    ret = strcat(ret, "]\n");
    return (ret);
}

char *look_left(trantor_t *data) {
    int x = data->drone->x % data->size[0],y=data->drone->y%data->size[1],count;
    char *loc, *ret = malloc(sizeof(char) * 2);
    strcpy(ret, "[");
    for (int i = 0; i < 4; i++) {
        count = 0;
        do {
            loc = getpos_content(data, x, y);
            if((ret = realloc(ret, sizeof(char) *
                (strlen(ret) + strlen(loc) + 5))) == NULL)
                exit(84);
            ret = strcat(ret, loc);
            ret = strcat(ret, " ,");
            free(loc);
            count ++;
            y --;
        } while (count != 1 + 2 * i);
        y = data->drone->y + i + 1;
        x--;
    }
    ret = strcat(ret, "]\n");
    return (ret);
}

char *look_up(trantor_t *data) {
    int x = data->drone->x % data->size[0],y=data->drone->y%data->size[1],count;
    char *loc, *ret = malloc(sizeof(char) * 2);
    strcpy(ret, "[");
    for (int i = 0; i < 4; i++) {
        count = 0;
        do {
            loc = getpos_content(data, x, y);
            if((ret = realloc(ret, sizeof(char) *
                (strlen(ret) + strlen(loc) + 5))) == NULL)
                exit(84);
            ret = strcat(ret, loc);
            ret = strcat(ret, " ,");
            free(loc);
            count ++;
            x ++;
        } while (count != 1 + 2 * i);
        x = data->drone->x - i - 1;
        y--;
    }
    ret = strcat(ret, "]\n");
    return (ret);
}

char *look_down(trantor_t *data) {
    int x = data->drone->x % data->size[0],y=data->drone->y%data->size[1],count;
    char *loc, *ret = malloc(sizeof(char) * 2);
    strcpy(ret, "[");
    for (int i = 0; i < 4; i++) {
        count = 0;
        do {
            loc = getpos_content(data, x, y);
            if((ret = realloc(ret, sizeof(char) *
                (strlen(ret) + strlen(loc) + 5))) == NULL)
                exit(84);
            ret = strcat(ret, loc);
            ret = strcat(ret, " ,");
            free(loc);
            count ++;
            x --;
        } while (count != 1 + 2 * i);
        x = data->drone->x + i + 1;
        y++;
    }
    ret = strcat(ret, "]\n");
    return (ret);
}

char *look(trantor_t *data) {
    char *(*fnptr[])(trantor_t *) = {look_up, look_right, look_down, look_left};
    return (fnptr[data->drone->orientation](data));
}