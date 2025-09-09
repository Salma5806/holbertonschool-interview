#include "binary_trees.h"

/**
 * create_avl - Builds an AVL tree from a sorted array (recursive helper)
 * @array: pointer to the first element of the array
 * @start: start index of the current subarray
 * @end: end index of the current subarray
 * @parent: parent node of the current root
 * Return: pointer to the root node of the subtree, or NULL on failure
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
    avl_t *node;
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    node = binary_tree_node(parent, array[mid]);
    if (!node)
        return (NULL);

    node->left = create_avl(array, start, mid - 1, node);
    node->right = create_avl(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (create_avl(array, 0, (int)size - 1, NULL));
}