#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	/* Insert each element from the array into the BST */
	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{ 
			bst_free(root);
			return (NULL);
		}
	}

	return (root);
}

/**
 * bst_free - Frees a binary search tree
 * @tree: Pointer to the root node of the tree to free
 */
 void bst_free(bst_t *tree)
{
	if (tree == NULL)
		return;

	bst_free(tree->left);
	bst_free(tree->right);
	free(tree);
}
