#include "lists.h"
/**
 * find_listint_loop - Find the loop in the list.
 * @head: it's a head of list to find loop
 * Return: node where loop is located otherwise NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *x, *y;

	x = head;
	y = x;
	while (x && y && y->next)
	{
		x = x->next;
		y = y->next->next;
		if (x == y)
		{
			x = head;
			while (x && y)
			{
				if (x == y)
					return (x);
				x = x->next;
				y = y->next;
			}
		}
	}
	return ('\0');
}
