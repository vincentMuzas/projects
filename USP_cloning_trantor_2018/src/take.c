/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** take
*/

#include "trantor.h"

int remove_resource(map_t *elem, char *what) {
	char *last = elem->resource[elem->quantity];
	for (int i = 0; i < elem->quantity; i++) {
		if (!strcmp(elem->resource[i], what)) {
			free(elem->resource[i]);
			elem->resource[i] = last;
			elem->resource[elem->quantity] = NULL;
			elem->quantity --;
			return (1);
		}
	}
	return (0);
}

char *take(trantor_t *data, char *cmd) {
	map_t *elem = &data->map[data->drone->y % data->size[1]]
							[data->drone->x % data->size[0]];
	char **wt = my_str_to_wordtab(cmd);
	char *resources[] = {"food", "sibur", "phiras", "linmate",
						"mendiane", "thystame", "deraumere", NULL};
	char *ret = malloc(sizeof(char) * 4);
	strcpy(ret, "ko\n");
	for (int i = 0; wt[i] != NULL; i++) {
		for (int j = 0; resources[j] != NULL; j++) {
			if (!strcmp(wt[i], resources[j])) {
				if (remove_resource(elem, resources[j])) {
					data->drone->inventory[j] ++;
					strcpy(ret, "ok\n");
				}
			}
		}
	}
	free_wordtab(wt);
	return (ret);
}