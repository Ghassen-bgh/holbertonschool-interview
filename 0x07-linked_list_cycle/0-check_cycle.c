#include "lists.h"


/**
 * check_cycle - check cycle in linked list
 * @list: linked list
 * Return: 0 if there is a cycle 1 if not
 */

int check_cycle(listint_t *list)
{
    listint_t *a = list;
    listint_t *b = list;

    while (a && b && b->next)
    {
        a = a->next;
        b = b->next->next;
        if (a == b)
            return (1);
    }
    return (0);
}
