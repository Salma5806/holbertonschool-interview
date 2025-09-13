#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* ==================== Struct Definitions ==================== */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* For heap specifically */
typedef struct binary_tree_s heap_t;

/* ==================== Function Prototypes ==================== */

/* heap_extract function */
int heap_extract(heap_t **root);

/* Optional helpers used in main (you don't need to implement them) */
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

#endif /* BINARY_TREES_H */