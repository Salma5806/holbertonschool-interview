#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer pointer
 * @b: Second integer pointer
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * sift_down - Heapify subtree rooted at index i
 * @array: Array of integers
 * @size: Total size of the array
 * @n: Size of the heap being worked on
 * @i: Root index of the subtree
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap_ints(&array[i], &array[largest]);
        print_array(array, size);
        sift_down(array, size, n, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    ssize_t i;

    if (!array || size < 2)
        return;

    /* Build max heap */
    for (i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, size, i);

    /* Extract elements from heap */
    for (i = size - 1; i > 0; i--)
    {
        swap_ints(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, size, i, 0);
    }
}