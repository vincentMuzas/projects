/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** inventory
*/

#include "trantor.h"

char *inventory(trantor_t *data) {
	char *ret = malloc(sizeof(char) * 2);
	char *names[] = {"food", "sibur", "phiras", "linmate",
					"mendiane", "thystame", "deraumere"};
	strcpy(ret, "[");
	for (int i = 0; i < 7; i++) {
		ret = realloc(ret, sizeof(char) * (strlen(ret) + strlen(names[i])+10));
		sprintf(ret, "%s%s %d", ret, names[i], data->drone->inventory[i]);
		if (i != 6)
			strcat(ret, ", ");
	}
	strcat(ret, "]\n");
	return (ret);
}