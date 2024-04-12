#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 100);
	if (queue == NULL)
		return;

	queue[rear] = (binary_tree_t *)tree;
	rear = (rear + 1) % 100;

	while (front != rear)
	{
		binary_tree_t *current = queue[front];

		front = (front + 1) % 100;

		func(current->n);

		if (current->left != NULL)
		{
			queue[rear] = current->left;
			rear = (rear + 1) % 100;
		}

		if (current->right != NULL)
		{
			queue[rear] = current->right;
			rear = (rear + 1) % 100;
		}
	}

	free(queue);
}
