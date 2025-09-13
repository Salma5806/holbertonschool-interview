#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular list
 * @list: Pointer to the head of the list
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new, *tail;

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

    tail = (*list)->prev;

    tail->next = new;
    new->prev = tail;
    new->next = *list;
    (*list)->prev = new;

    return (new);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular list
 * @list: Pointer to the head of the list
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new;

    new = add_node_end(list, str);
    if (!new)
        return (NULL);

    *list = new;
    return (new);
}