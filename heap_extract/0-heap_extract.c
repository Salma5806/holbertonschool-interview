#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measure height of a binary tree
 * @tree: pointer to tree root
 * Return: height, 0 if NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
    size_t left, right;

    if (!tree)
        return (0);

    left = tree_height(tree->left);
    right = tree_height(tree->right);

    return ((left > right ? left : right) + 1);
}

/**
 * get_last_node - return the last node in level order traversal
 * @root: pointer to root node
 * Return: pointer to last node
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t **queue, *node = NULL;
    size_t front = 0, back = 0, size, h;

    if (!root)
        return (NULL);

    h = tree_height(root);
    size = (1 << h); /* max possible nodes at this height */
    queue = malloc(sizeof(*queue) * size);
    if (!queue)
        return (NULL);

    queue[back++] = root;
    while (front < back)
    {
        node = queue[front++];
        if (node->left)
            queue[back++] = node->left;
        if (node->right)
            queue[back++] = node->right;
    }
    free(queue);
    return (node);
}

/**
 * heapify_down - restores Max Heap property starting from root
 * @root: pointer to heap root
 */
void heapify_down(heap_t *root)
{
    heap_t *largest;
    int tmp;

    while (root)
    {
        largest = root;
        if (root->left && root->left->n > largest->n)
            largest = root->left;
        if (root->right && root->right->n > largest->n)
            largest = root->right;

        if (largest == root)
            break;

        tmp = root->n;
        root->n = largest->n;
        largest->n = tmp;

        root = largest;
    }
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to heap root
 * Return: value stored at root, or 0 if failure
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *parent;
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last = get_last_node(*root);

    if (last == *root) /* heap has only one node */
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    /* Replace root value with last node's value */
    (*root)->n = last->n;
    parent = last->parent;
    if (parent->left == last)
        parent->left = NULL;
    else
        parent->right = NULL;
    free(last);

    /* Restore heap property */
    heapify_down(*root);

    return (value);
}