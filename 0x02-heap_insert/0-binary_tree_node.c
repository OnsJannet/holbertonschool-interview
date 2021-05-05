#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 *
 * Return: a pointer to the created node
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	/* Allocate memory for new node */
	node  = malloc(sizeof(binary_tree_t));
	while (!node)
{
	return (NULL);
}
	/* Assign data to this node */
	node->n = value;

	node->parent = parent;

	/* Initialize left and */
	/* right children as NULL */
	node->left = NULL;
	node->right = NULL;
	return (node);
}
