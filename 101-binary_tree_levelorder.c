#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/* Create a queue for level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 100);
	if (!queue)
		return;

	int front = 0, rear = 0;
	const binary_tree_t *current;

	/* Enqueue the root */
	queue[rear++] = (binary_tree_t *)tree;

	/* Loop until the queue is empty */
	while (front < rear)
	{
		current = queue[front++];

		/* Call the function with the value of the current node */
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left)
			  queue[rear++] = (binary_tree_t *)current->left;

		/* Enqueue the right child if it exists */
		if (current->right)
			  queue[rear++] = (binary_tree_t *)current->right;
	}

	/* Free the queue */
	free(queue);
}
