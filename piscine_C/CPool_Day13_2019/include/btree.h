/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** btree
*/

#ifndef BTREE_H_
#define BTREE_H_

#include <stdlib.h>
#include <stddef.h>

typedef struct btree
{
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;

void btree_apply_infix(btree_t *root, int (*applyf)(void *));
void btree_apply_prefix(btree_t *root, int (*applyf)(void *));
void btree_apply_suffix(btree_t *root, int (*applyf)(void *));
btree_t *btree_create_node(void *item);
void btree_insert_data(btree_t **root, void *item, int (*cmpf)());
size_t btree_level_count(btree_t const *root);
void btree_apply_by_level(btree_t *root, void (*applyf)(void *, int, int));

#endif /* !BTREE_H_ */
