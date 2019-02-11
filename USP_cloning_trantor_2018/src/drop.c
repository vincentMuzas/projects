/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** drop
*/

#include "trantor.h"

void add_resource(char *name, map_t *pos) {
    if ((pos->resource[pos->quantity] = malloc(sizeof(char) * 16)) == NULL)
        exit(84);
    strcpy(pos->resource[pos->quantity], name);
    pos->quantity ++;
}

char *drop(trantor_t *data, char *msg) {
    char **wt = my_str_to_wordtab(msg);
    char *resources[] = {"food", "sibur", "phiras", "linmate",
                        "mendiane", "thystame", "deraumere", NULL};
    char *ret = malloc(sizeof(char) * 4);
    map_t *pos = &data->map[data->drone->y % data->size[1]]
                            [data->drone->x % data->size[0]];
    strcpy(ret, "ko\n");
    for (int i = 1; wt[i] != NULL; i++) {
        for (int j = 0; resources[j] != NULL; j++) {
            if (!strcmp(resources[j],wt[i])&& data->drone->inventory[j]>0) {
                data->drone->inventory[j] --;
                add_resource(resources[j], pos);
                strcpy(ret, "ok\n");
            }
        }
    }
    free_wordtab(wt);
    return (ret);
}