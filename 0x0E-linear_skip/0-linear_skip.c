#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - optimize the time complexity of a search
 * in a singly linked list
 *
 * @list: List
 * @value: value
 *
 * Return: Always EXIT_SUCCESS
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = NULL;

	if (!list)
		return (NULL);

	tmp = list;
	while (tmp->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		tmp->express->index, tmp->express->n);
		if (tmp->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					tmp->index, tmp->express->index);
			break;
		}
	tmp = tmp->express;
	}

	if (!tmp->express)
	{
		list = tmp;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				tmp->index, list->index);
	}

	list = tmp;

	while (list != tmp->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
