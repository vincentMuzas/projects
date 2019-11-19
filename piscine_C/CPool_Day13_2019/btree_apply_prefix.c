/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** apply_prefix
*/

#include "btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    applyf(root->item);
    if (root->left != NULL)
        btree_apply_prefix(root->left, applyf);
    if (root->right != NULL)
        btree_apply_prefix(root->right, applyf);
}