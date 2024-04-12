#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Create a queue for level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 100);
	if (!queue)
		return (0);

	int front = 0, rear = 0;
	const binary_tree_t *current;

	/* Enqueue the root */
	queue[rear++] = (binary_tree_t *)tree;

	/* Loop until the queue is empty */
	while (front < rear)
	{
		current = queue[front++];

		/* If a NULL child is encountered, mark that a non-full node is found */
		if (!current)
			return (0);

		/* Enqueue the left child */
		if (current->left)
			queue[rear++] = (binary_tree_t *)current->left;

		/* Enqueue the right child */
		if (current->right)
			queue[rear++] = (binary_tree_t *)current->right;
	}

	/* Check if all nodes are visited, except the last level */
	while (rear > 1)
	{
		current = queue[--rear];

		/* If a non-full node is encountered, the tree is not complete */
		if (!current)
			return (0);
	}

	/* Free the queue */
	free(queue);

	/* If no irregularities are found, the tree is complete */
	return (1);
}
