#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges two subarrays into one sorted array
 * @array: original array
 * @temp: temporary array for merging
 * @left: left index
 * @mid: middle index
 * @right: right index
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	for (size_t l = left; l <= mid; l++)
	{
		printf("%d", array[l]);
		if (l < mid)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (size_t l = mid + 1; l <= right; l++)
	{
		printf("%d", array[l]);
		if (l < right)
			printf(", ");
	}
	printf("\n");

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge_sort_rec - recursively splits and merges the array
 * @array: array to sort
 * @temp: temporary array
 * @left: left index
 * @right: right index
 */
void merge_sort_rec(int *array, int *temp, size_t left, size_t right)
{
	if (left >= right)
		return;

	size_t mid = left + (right - left) / 2;

	merge_sort_rec(array, temp, left, mid);
	merge_sort_rec(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - sorts an array of integers using merge sort
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_rec(array, temp, 0, size - 1);

	free(temp);
}