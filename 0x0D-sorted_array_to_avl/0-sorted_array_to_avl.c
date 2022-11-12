#include "binary_trees.h"
/**
 * ArrayToAVL - function that builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @start: start index of the array
 * @end: end index of the array
 * @parent: pointer to the parent node of the node to create
 * Return: pointer to the created node, or NULL on failure
 */

avl_t *ArrayToAVL(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = ArrayToAVL(array, start, mid - 1, node);
	node->right = ArrayToAVL(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size);
{
	avl_t *root;

	if (!array || size == 0)
		return (NULL);

	root = ArrayToAVL(array, 0, size - 1, NULL);
	return (root);
}
