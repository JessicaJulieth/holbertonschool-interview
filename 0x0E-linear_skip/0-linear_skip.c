#include "search.h"

/**
 * linear_skip - Find a value in a sorted skip list
 * @list: Is a pointer to the head of the skip list to search in.
 * @value: Is the value to search for.
 *
 * Return: Pointer or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *mov = NULL, *nd = NULL;
	char x[24] = "Value checked at index ";
	char y[29] = "Value found between indexes ";

	if (list == NULL)
		return (NULL);
	mov = list;
	nd = list;
	while (nd->nd)
	{
		mov = nd;
		nd = nd->nd;
		printf("%s[%ld] = [%d]\n", x, nd->nd, nd->n);
		if (nd->n >= value)
			break;
		if (nd->nd == NULL)
		{
			mov = nd;
			while (nd->next)
				nd = nd->next;
		}
	}
	printf("%s[%ld] and [%ld]\n", x, mov->index, nd->index);
	while (mov->next && mov->index != nd->index)
	{
		printf("%s[%ld] = [%d]\n", x, mov->index, mov->n);
		if (mov->n >= value)
			break;
		mov = mov->next;
	}
	if (mov->next == NULL)
		printf("%s[%ld] = [%d]\n", x, mov->index, mov->n);
	if (mov->n == value)
		return (mov);
	return (NULL);
}
