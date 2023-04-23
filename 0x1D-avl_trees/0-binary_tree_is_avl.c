#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * max - returns the max of two integers
 * @a: first integer
 * @b: second integer
 * Return: the max of a and b
*/
int max (int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * height - returns the height of a root node
 * @root: root node
 * Return: height of root node
*/
int height(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + max(height(root->left), height(root->right)));
}

/**
 * is_balanced - checks if a binary tree is balanced
 * @root: root node
 * Return: 1 if balanced, 0 otherwise
*/
int isBST(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);
	if (root->n < min || root->n > max)
		return (0);
	return (isBST(root->left, min, root->n - 1) &&
			isBST(root->right, root->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: root node
 * Return: 1 if valid AVL Tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (isBST(tree, INT_MIN, INT_MAX) == 0)
		return (0);
	if (abs(height(tree->left) - height(tree->right)) > 1)
		return (0);
	if (tree->left != NULL && binary_tree_is_avl(tree->left) == 0)
		return (0);
	if (tree->right != NULL && binary_tree_is_avl(tree->right) == 0)
		return (0);
	return (1);
}
