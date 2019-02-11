/*
** EPITECH PROJECT, 2018
** cloning
** File description:
** map
*/

#include "trantor.h"

void draw_map(map_t** map, size_t *size, drone_t *drone) {
    drone_t *start_pt = drone;
    for (unsigned int i = 0; i < size[1]; i++) {
        printf("[");
        for (unsigned int j = 0; j < size[0]; j++) {
            drone = start_pt;
            while (drone != NULL) {
                if (drone->x % size[0] == j && drone->y % size[1] == i)
                    printf(" player");
                drone = drone->next;
            }
            for (int index = 0; index < map[i][j].quantity; index++) {
                printf(" %s", map[i][j].resource[index]);
            }
            printf(",");
        }
        printf("]\n");
    }
}

void free_map(map_t** map, size_t *size) {
    int width = size[0], height = size[1];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < map[i][j].quantity; k++)
                free (map[i][j].resource[k]);
            free(map[i][j].resource);
        }
        free(map[i]);
    }
    free(map);
}

void generate_resource(map_t *place, int index) {
    char *resources[] = {"linmate", "deraumere", "sibur",
                        "mendiane", "phiras", "thystame"};
    int rdvalue = rand() % 6;
    if (!(place->resource[index] = malloc(sizeof(char) * 16)))
        exit (84);
    strcpy(place->resource[index], resources[rdvalue]);
    place->quantity = index + 1;
}

map_t **create_map(int width, int height) {
    map_t **map;

    if ((map = malloc(sizeof(map_t *) * height)) == NULL)
        exit (84);
    srand((long)&map);
    for (int i = 0; i < height; i++) {
        if ((map[i] = malloc(sizeof(map_t) * width)) == NULL)
            exit (84);
        bzero(map[i], sizeof(map_t) * height);

        for (int j = 0; j < width; j++) {
            if ((map[i][j].resource = malloc(sizeof(char *) * 128)) == NULL)
                exit (84);
            map[i][j].quantity = 0;
            for (int count = 0; rand() % 4 == 0; count++) {
                generate_resource(&map[i][j], count);
            }
        }
    }
    return (map);
}