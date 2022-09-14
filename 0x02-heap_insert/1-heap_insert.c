#include "binary_trees.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_size - function that get the size of a binary tree
 * @tree: pointer to the root
 * Return: size of the binary tree
 */

int binary_size(const binary_tree_t *tree)
{
	int x;

	if (tree == NULL)
		return (0);
	x = 0;
	if (tree)
		x = 1;
	x += binary_size(tree->left);
	x += binary_size(tree->right);

	return (x);
}

/**
 * binary_check - Check binary
 * @tree: Pointer
 * Return: 1 if true or 0 if false
 */

int binary_check(const binary_tree_t *tree)
{
	int m, n;

	if (tree == NULL)
		return (0);
	m = binary_size(tree->left);
	n = binary_size(tree->right);
	if (m == n)
		return (1);
	return (0);
}

/**
 * sort_Binary - Sorts a binary tree
 * @new: pointer to the root
 * Return: void function
 */

void sort_binary(heap_t **new)
{
	heap_t *j;
	int old;

	j = *new;
	while (j->parent != NULL)
	{
		if (j->n > j->parent->n)
		{
			old = j->n;
			j->n = j->parent->n;
			j->parent->n = old;
			*new = j->parent;
		}
		j = j->parent;
	}
}

/**
 * nd_Add - function that finds and return the parent address of a node
 * @root: Pointer
 * Return: Pointer
 */

heap_t *nd_Add(heap_t *root)
{
	if (binary_size(root->left) == 0 || binary_size(root->right) == 0)
		return (root);
	else if (binary_check(root->left) == 1 &&
			 binary_check(root->right) == 1 &&
			 binary_size(root->left) == binary_size(root->right))
		return (nd_Add(root->left));
	else if ((binary_size(root->left) > binary_size(root->right)) &&
			 binary_check(root->left) == 0)
		return (nd_Add(root->left));
	else if ((binary_size(root->left) > binary_size(root->right)) &&
			 binary_check(root->left) == 1)
		return (nd_Add(root->right));
	return (root);
}

/**
 * heap_insert - Inserts value to binary heap
 * @root: Pointer 
 * @value: value
 * Return: Pointer
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *nd;

	if (*root == NULL)
		nd = NULL;
	else
		nd = nd_Add(*root);
	new = binary_tree_node(nd, value);
	if (new == NULL)
		return (NULL);
	if (nd == NULL)
		*root = new;
	else if (nd->left == NULL)
		nd->left = new;
	else
		nd->right = new;
	sort_binary(&new);
	return (new);
}
