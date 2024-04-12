#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * bst_minimum - Finds the node with the minimum value in a BST
 * @node: A pointer to the root node of the BST
 *
 * Return: A pointer to the node with the minimum value
 */
static bst_t *bst_minimum(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			bst_t *right_child = root->right;
			free(root);
			return (right_child);
		}
		else if (!root->right)
		{
			bst_t *left_child = root->left;
			free(root);
			return (left_child);
		}
		bst_t *temp = bst_minimum(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
