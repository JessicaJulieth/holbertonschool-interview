#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
* binary_tree_node - Prototype
* @parent: Is a pointer to the parent node of the node to create
* @value: Is value to put in the new node
* Return: A pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}