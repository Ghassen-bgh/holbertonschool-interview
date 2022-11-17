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
		for (list = tmp; list->next; list = list->next)
			;
		printf("Value found between indexes [%lu] and [%lu]/n",
		       tmp->index, list->index);
	}
	for (list = tmp; list != tmp->express; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]/n",
		       list->index, list->n);
		if (list->n == value)
			return (list);
	}
	return (NULL);
}
