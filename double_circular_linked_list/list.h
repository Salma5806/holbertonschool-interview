#ifndef LIST_H
#define LIST_H

/**
 * struct List - Node of a double circular linked list
 * @str: String stored in the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/* Function prototypes */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
