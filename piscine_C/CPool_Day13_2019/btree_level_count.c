/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** btree_level_count
*/

#include "btree.h"

size_t btree_level_count(btree_t const *root)
{
    size_t left = 0, right = 0;
    if (root == NULL)
        return (0);
    left = btree_level_count(root->left);
    right = btree_level_count(root->right);
    return (((right < left) ? left : right) + 1);
}