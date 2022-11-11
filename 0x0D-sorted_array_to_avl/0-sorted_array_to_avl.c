#include "binary_trees.h"
/**
 * sorted_array_to_avl - convert array to avl tree
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of element in the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *ret = NULL;

	ret = ret_tree(array, 0, (int)size - 1);
	if (!ret)
		return (NULL);
	return (ret);
}

/**
 * new_node - create node of avl_t
 * @n: number
 * Return: node or NULL
 */
avl_t *new_node(int n)
{
	avl_t *node = NULL;

	if (n == 0)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = n;
	return (node);
}

/**
 * ret_tree - Node recursive 
 * @array: Array.
 * @init: Init.
 * @end: End.
 * Return: The tree
 */
avl_t *ret_tree(int *array, int init, int end)
{
	avl_t *left = NULL, *right = NULL, *parent = NULL;
	size_t n = 0;

	if (init > end)
		return (NULL);
	n = (init + end) / 2;
	left = ret_tree(array, init, n - 1);
	right = ret_tree(array, n + 1, end);
	parent = new_node(array[n]);
	if (!parent)
		return (NULL);
	parent->left = left;
	parent->right = right;
	if (left)
		left->parent = parent;
	if (right)
		right->parent = parent;
	return (parent);
}
