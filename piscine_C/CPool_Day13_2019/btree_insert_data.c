/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** btree_insert_data
*/

#include "btree.h"

void btree_insert_data(btree_t **root, void *item, int (*cmpf)())
{
    btree_t *node = *root;
    if (*root == NULL) {
        *root = btree_create_node(item);
    }
    while (node != NULL) {
        if (cmpf(node->item, item) >= 0) {
            if (node->left == NULL) {
                node->left = btree_create_node(item);
                break;
            }
            node = node->left;
        }
        else {
            if (node->right == NULL) {
                node->right = btree_create_node(item);
                break;
            }
            node = node->right;
        }
    }
}