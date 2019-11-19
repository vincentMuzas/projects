/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** btree_apply_sufix
*/

#include "btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void *))
{
    if (root->left != NULL)
        btree_apply_suffix(root->left, applyf);
    if (root->right != NULL)
        btree_apply_suffix(root->right, applyf);
    applyf(root->item);
}