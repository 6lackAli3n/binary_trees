#include "binary_trees.h"
#include <stddef.h>
#include <limits.h>
/**
 * is_bst - Helper function to check if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value a node in the tree can have
 * @max: The maximum value a node in the tree can have
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
