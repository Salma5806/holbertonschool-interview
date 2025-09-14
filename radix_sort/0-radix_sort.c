#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum value in an array
 * @array: The array
 * @size: Size of the array
 *
 * Return: The maximum integer
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort_radix - Stable counting sort used in radix sort
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The current digit exponent (1, 10, 100, etc.)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output, count[10] = {0};
    size_t i;

    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    /* Count occurrences of each digit */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Update count[i] so it contains actual position of this digit in output[] */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build output array (stable order, traverse from end) */
    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / exp) % 10]--;
    }

    /* Copy sorted numbers into array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sort an array using LSD radix sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);

    /* Sort by each digit (exp = 1 -> unit, exp = 10 -> tens, etc.) */
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}