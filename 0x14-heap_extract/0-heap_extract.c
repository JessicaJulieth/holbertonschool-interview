#include "binary_trees.h"
/**
 * heap_max - Fix the heap_max
 * @root: head of the heap tree
 * Return: Nothing
 */
void heap_max(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int tem_num = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}

		if (root->n >= child->n)
			break;

		tem_num = root->n;
		root->n = child->n;
		child->n = tem_num;

		root = child;
	}
}

/**
 * get_nodes - get the number of nodes of heap tree
 * @root: head of the heap tree
 * Return: all the nodes in heap tree
 */
int get_nodes(heap_t *root)
{
	int l = 0, r = 0;

	if (!root)
		return (0);

	l = get_nodes(root->left);
	r = get_nodes(root->right);

	return (1 + l + r);
}

/**
 * last_n - Last node in heap_min
 * @root: Heap tree
 * Return: Last node in heap_min
 */
binary_tree_t *last_node(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *last_n = NULL;

	size_heap = get_nodes(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_n = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			last_n = last_n->right;
		else
			last_n = last_n->left;
	}

	return (last_n);
}
/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Is a double pointer to the root node of the heap.
 * Return: The value stored in the root node AND If the function fails, return 0
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *last_n = NULL, *head_node = NULL;
	int extracted_num = 0;

	if (!root || !*root)
		return (0);
	head_node = *root;
	if (!head_node->left && !head_node->right)
	{
		extracted_num = head_node->n;
		free(head_node);
		*root = NULL;
		return (extracted_num);
	}

	head_node = *root;
	extracted_num = head_node->n;

	last_n = last_node(*root);

	if (last_n->parent->left == last_n)
		last_n->parent->left = NULL;
	else
		last_n->parent->right = NULL;

	last_n->left = head_node->left;
	last_n->right = head_node->right;
	last_n->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = last_n;
	if (head_node->right)
		head_node->right->parent = last_n;

	*root = last_n;
	free(head_node);

	heap_max(*root);

	return (extracted_num);
}
