#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *x = NULL, *y = NULL;

	if (list == NULL)
		return (0);

	x = y = list;

	while (x && y && y->next)
	{
		x = x->next;
		y = y->next->next;
		if (x == y)
		{
			return (1);
		}
	}
	return (0);
}
