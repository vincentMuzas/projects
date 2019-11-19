/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** btree_search_item
*/

#include "btree.h"

void *btree_search_item(btree_t const *root,void const *data_ref,int (*cmpf()))
{
    void *ret;
    if (root == NULL)
        return (NULL);
    if ((ret = btree_search_item(root->left, data_ref, cmpf)) != NULL)
        return (ret);
    if (cmpf(data_ref, root->item) == 0)
        return ((void *) root);
    if ((ret = btree_search_item(root->right, data_ref, cmpf)) != NULL)
        return (ret);
    return (NULL);
}