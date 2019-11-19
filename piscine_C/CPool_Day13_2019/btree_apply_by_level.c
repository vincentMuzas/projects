/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** btree_apply_by_level
*/

#include "btree.h"

static void btree_apply_by_level_rec(btree_t *root,
        void (*applyf)(void *, int, int), int lv, int ract)
{
    static char first = 1;
    if (lv == 0) {
        first = 1;
        return;
    }
    if (root == NULL)
        return;
    if (lv == 1) {
        (*applyf)(root->item, ract, first);
        first = 0;
    } else {
        btree_apply_by_level_rec(root->left, applyf, lv - 1, ract);
        btree_apply_by_level_rec(root->right, applyf, lv - 1, ract);
    }
}

void btree_apply_by_level(btree_t *root, void (*applyf)(void *, int, int))
{
    for (int i = 1, h = btree_level_count(root); i < h; i++) {
        btree_apply_by_level_rec(root, applyf, i, i);
        btree_apply_by_level_rec(root, applyf, 0, 0);
    }
}