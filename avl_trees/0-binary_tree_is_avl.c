#include "binary_trees.h"
#include <limits.h>

/**
 * height - Compute the height of a binary tree
 * @tree: Pointer to root
 *
 * Return: Height of tree, 0 if NULL
 */
int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * is_avl_helper - Check if a tree is AVL
 * @tree: Pointer to root
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_h, right_h, balance;

	if (tree == NULL)
		return (1);

	/* BST property check */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Check balance factor */
	left_h = height(tree->left);
	right_h = height(tree->right);
	balance = left_h - right_h;
	if (balance > 1 || balance < -1)
		return (0);

	/* Recurse for left and right subtrees with updated min/max */
	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to root node
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}