#include "lists.h"

listint_t *reverse(listint_t *head)
{
	listint_t *x = head;
	listint_t *y = head;
	listint_t *z = NULL;

	while (x)
	{
		x = y->next;
		y->next = z;
		z = y;
		y = x;
	}
	return (z);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node in a linked list
 * Return: 1 if its a palindrome, 0 if it isn't
 */
int is_palindrome(listint_t **head)
{
	listint_t *m, *n, *current, *i;

	current = *head;
	m = *head;
	n = *head;

	while (current && n->next && n->next->next)
	{
		m = m->next;
		n = n->next->next;
	}
	i = reverse(m);
	while (i && current)
	{
		if (i->n != current->n)
			return (0);

		i = i->next;
		current = current->next;
	}
	return (1);
}
