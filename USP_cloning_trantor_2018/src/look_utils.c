/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** look2
*/

#include "trantor.h"

char *str_clean(char *str) {
    char cpy[strlen(str)];
    int i = 0, j = 0;

    while (str[j] != 0) {
        while (str[j] == ' ' && (str[j + 1] == ' ' || str[j + 1] == 0))
            j++;
        cpy[i] = str[j];
        i++;
        if (str[j] != 0)
            j++;
    }
    cpy[i] = 0;
    strcpy(str, cpy);
    return (str);
}

char *getpos_content(trantor_t *data, size_t x, size_t y) {
    char *ret = malloc(sizeof(char));
    map_t *pos;
    drone_t *drone = data->drone_list;

    ret[0] = 0;
    pos = &data->map[y % data->size[0]][x % data->size[1]];
    for (; drone != NULL; drone = drone->next) {
        if (drone->x % data->size[0] == x && drone->y % data->size[1] == y) {
            ret = realloc(ret, sizeof(char) *(strlen(ret)+strlen("player ")+1));
            ret = strcat(ret, "player ");
        }
    }
    for (int i = 0; i < pos->quantity; i++) {
        ret = realloc(ret, strlen(ret) + strlen(pos->resource[i]) + 1);
        ret = strcat(ret, pos->resource[i]);
        ret = append_char(ret, ' ');
    }
    ret = str_clean(ret);
    return (ret);
}