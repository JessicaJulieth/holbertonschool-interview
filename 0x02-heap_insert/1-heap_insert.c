#include "binary_trees.h"
#include "stdio.h"

/**
 * size - Size of a binary tree
 * @tree: pointer to the root
 * Return: size of the binary tree
 */

int size(const binary_tree_t *tree)
{
	int X;

	if (tree == NULL)
		return (0);
	X = 0;
	if (tree)
		X = 1;
	X += size(tree->left);
	X += size(tree->right);

	return (X);
}

/**
 * binary_tree_is_perfect - Checks a tree
 * @tree: Pointer
 * Return: 1 if true or 0 if false
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int p1, p2;

	if (tree == NULL)
		return (0);
	p1 = size(tree->left);
	p2 = size(tree->right);
	if (p1 == p2)
		return (1);
	return (0);
}

/**
 * sort_binary_tree - Sorts a binary tree
 * @new: Pointer 
 * Return: void function
 */

void sort_binary_tree(heap_t **new)
{
	heap_t *aux;
	int old;

	aux = *new;
	while (aux->parent != NULL)
	{
		if (aux->n > aux->parent->n)
		{
			old = aux->n;
			aux->n = aux->parent->n;
			aux->parent->n = old;
			*new = aux->parent;
		}
		aux = aux->parent;
	}
}

/**
 * parent_address - Finds and return the parent address of a node
 * @root: Pointer
 * Return: Pointer
 */

heap_t *parent_address(heap_t *root)
{
	if (size(root->left) == 0 || size(root->right) == 0)
		return (root);
	else if (binary_tree_is_perfect(root->left) == 1 &&
			 binary_tree_is_perfect(root->right) == 1 &&
			 size(root->left) == size(root->right))
		return (parent_address(root->left));
	else if ((size(root->left) > size(root->right)) &&
			 binary_tree_is_perfect(root->left) == 0)
		return (parent_address(root->left));
	else if ((size(root->left) > size(root->right)) &&
			 binary_tree_is_perfect(root->left) == 1)
		return (parent_address(root->right));
	return (root);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value of the node to be inserted
 * Return: Pointer
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (*root == NULL)
		parent = NULL;
	else
		parent = parent_address(*root);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent == NULL)
		*root = new;
	else if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;
	sort_binary_tree(&new);
	return (new);
}