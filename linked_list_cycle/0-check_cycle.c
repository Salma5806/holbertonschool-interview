#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 1 if there is a cycle, 0 if not
 */
int check_cycle(listint_t *list)
{
    const listint_t *temp, *temp2;
    if (list == NULL)
    {
        return 0;
    }
    temp = list;
    temp2 = temp->next;
    while (temp != NULL && temp2 != NULL && temp2->next != NULL)
    {
        if (temp == temp2)
        {
            return 1;
        }
        temp = temp->next;
        temp2 = temp2->next->next;
    }
    return 0;
}