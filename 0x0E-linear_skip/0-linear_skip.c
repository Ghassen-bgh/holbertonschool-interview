#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list;

	if (!list)
		return (NULL);
	while (tmp->express)
	{
		printf("Value checked at index [%lu] = [%d]/n",
		       tmp->express->index, tmp->express->n);
		if (tmp->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]/n",
			       tmp->index, tmp->express->index);
			break;
		}
		tmp = tmp->express;
	}
	if (!tmp->express)
	{
		tmp = tmp->express;
		while (tmp->next)
			tmp = tmp->next;
		printf("Value found between indexes [%lu] and [%lu]/n",
		       tmp->index, tmp->express->index);
	}
	while (tmp)
	{
		printf("Value checked at index [%lu] = [%d]/n",
		       tmp->index, tmp->n);
		if (tmp->n == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
