#include "binary_trees.h"
#include <stddef.h>
/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 * */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (!tree)
		return (NULL);

	/* If tree is empty, create a new node and make it the root */
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = NULL;
	new_node = *tree;

	/* Find the appropriate position to insert the new node */
	while (new_node)
	{
		parent = new_node;

		if (value < new_node->n)
			new_node = new_node->left;
		else if (value > new_node->n)
			new_node = new_node->right;
		else
			return (NULL); /* Value already exists, ignore it */
	}

	/* Create the new node and insert it as a child of the parent */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

