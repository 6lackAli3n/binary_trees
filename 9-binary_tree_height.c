#include "binary_trees.h"
#include <stddef.h>
/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* Base case: if tree is NULL, height is 0 */
	if (tree == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return the height of the taller subtree, plus 1 for the current node */
	return (1 + (left_height > right_height ? left_height : right_height));
}
