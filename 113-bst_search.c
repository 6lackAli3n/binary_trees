#include "binary_trees.h"
#include <stddef.h>
/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: A pointer to the node containing a value equals to `value`, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}
