#include "lists.h"

/**
 * new_node - New node of  listint_t
 * @number: new node
 *
 * Return: Address
 */

listint_t *new_node(int number)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;

	return (new);
}


/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the first node of the linked list
 * @number: integer to insert
 *
 * Return: the address of the new node, or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *x;
	listint_t *y;
	listint_t *new;

	x = *head;
	y = *head;
	new = new_node(number);

	if (!head || !new)
		return (NULL);

	if (!*head)
	{
		*head = new;
		return (new);
	}

	if (new->n < (*head)->n)
	{
		new->next = (*head);
		*head = new;
		return (new);
	}

	while (x && *head)
	{
		if (x->next == NULL)
		{
			x->next = new;
			new->next = NULL;
		}
		if (x->n > new->n)
		{
			new->next = x;
			y->next = new;
			break;
		}
		y = x;
		x = x->next;
	}
	return (new);
}
