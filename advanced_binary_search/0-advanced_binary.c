#include "search_algos.h"

/**
 * print_subarray - Prints the current subarray being searched
 * @array: Pointer to the first element of the array
 * @left: Left index
 * @right: Right index
 */
void print_subarray(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * recursive_search - Recursive helper for advanced_binary
 * @array: Pointer to the first element of the array
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index of first occurrence, or -1 if not found
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_subarray(array, left, right);

    mid = (left + right) / 2;

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return ((int)mid);
        return (recursive_search(array, left, mid, value));
    }
    else if (array[mid] < value)
    {
        return (recursive_search(array, mid + 1, right, value));
    }
    else
    {
        if (mid == 0) /* avoid size_t underflow */
            return (-1);
        return (recursive_search(array, left, mid - 1, value));
    }
}

/**
 * advanced_binary - Searches for the first occurrence of a value in a
 *                   sorted array of integers using advanced binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of value or -1 if not found / array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (recursive_search(array, 0, size - 1, value));
}