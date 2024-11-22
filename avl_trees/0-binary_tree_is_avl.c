#include "binary_trees.h"
#include <stdlib.h>

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed for the current node
 * @max: Maximum value allowed for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (1);

	/* Check BST property */
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	/* Compute heights of left and right subtrees */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Check AVL property */
	if (abs(left_height - right_height) > 1)
		return (0);

	/* Recursively check subtrees */
	return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl_helper(tree));
}
