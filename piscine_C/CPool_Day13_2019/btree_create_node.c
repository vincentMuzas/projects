/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** create_node
*/

#include "btree.h"

btree_t *btree_create_node(void *item)
{
    btree_t *new;
    new = malloc(sizeof(new));
    new->item = item;
    new->left = NULL;
    new->right = NULL;
    return (new);
}