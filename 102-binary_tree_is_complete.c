#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 100);
	if (queue == NULL)
		return (0);

	queue[rear] = (binary_tree_t *)tree;
	rear = (rear + 1) % 100;

	while (front != rear)
	{
		binary_tree_t *current = queue[front];

		front = (front + 1) % 100;

		if (current == NULL)
			break;

		queue[rear] = current->left;
		rear = (rear + 1) % 100;

		queue[rear] = current->right;
		rear = (rear + 1) % 100;
	}

	while (front != rear)
	{
		if (queue[front] != NULL)
		{
			free(queue);
			return (0);
		}
		front = (front + 1) % 100;
	}

	free(queue);
	return (1);
}
