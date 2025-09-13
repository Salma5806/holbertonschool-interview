#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add a new node at the end of a double circular linked list
 * @list: Pointer to the head of the list
 * @str: String to store in the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *last;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;
	last->next = new;
	new->prev = last;
	new->next = *list;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - Add a new node at the beginning of a double circular linked list
 * @list: Pointer to the head of the list
 * @str: String to store in the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *last;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;
	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	*list = new;

	return (new);
}
