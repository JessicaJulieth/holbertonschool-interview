#include "list.h"
#include <stdlib.h>
#include <string.h>


/**
 * add_node_end - Adds a node to the end
 * @list: List.
 * @str: String.
 * Return: Address of node or NULL or failure.
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List *));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->prev = new;
	new->next = new;

	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (!list || !*list)
	{
		*list = new;
		return (new);
	}

	new->prev = (*list)->prev;
	new->prev->next = new;
	(*list)->prev = new;
	new->next = *list;

	return (new);
}


/**
 * add_node_begin - adds node at beginning
 * @list: List.
 * @str: String.
 * Return: Address of node, NULL or failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List *));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->prev = new;
	new->next = new;

	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (!list || !*list)
	{
		*list = new;
		return (new);
	}

	new->prev = (*list)->prev;
	new->prev->next = new;
	(*list)->prev = new;
	new->next = *list;

	*list = new;

	return (new);
}
