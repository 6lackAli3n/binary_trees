#include "binary_trees.h"
#include <stddef.h>
/**
 * binary_tree_postorder - Goes through a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Traverse the left subtree */
    binary_tree_postorder(tree->left, func);

    /* Traverse the right subtree */
    binary_tree_postorder(tree->right, func);

    /* Visit the current node */
    func(tree->n);
}
