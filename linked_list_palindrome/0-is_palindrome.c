#include "lists.h"

/**
 * is_palindrome - checks if a linked list is palindrome
 * @head: linked list head
 * Return: 1 if is palindrome or 0 if not
 */


int is_palindrome(listint_t **head)
{
    listint_t *slow_ptr = *head;
    listint_t *fast_ptr = *head;
    listint_t *prev = NULL;
    listint_t *second_half;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL)
    {
        second_half = slow_ptr->next;
    }
    else
    {
        second_half = slow_ptr;
    }

    prev->next = NULL;
    reverse_list(&second_half);

    is_palindrome = compare_lists(*head, second_half);

    reverse_list(&second_half);

    if (prev != NULL)
    {
        prev->next = slow_ptr;
    }
    else
    {
        *head = slow_ptr;
    }

    return is_palindrome;
}
