#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new, *node;
    node = *head;
    new = malloc(sizeof(listint_t));
    if(new == NULL)
        return (NULL);
    new->n = number;
    if(*head == NULL || new->n < (*head)->n)
    {
        new->next = *head;
        *head = new;
        return (new);
    }
    for(node =* head; node != NULL; node = node->next)
    {
        if(node->next == NULL || new->n < node->next->n)
        {
            new->next = node->next;
            node->next = new;
            break;
        }
    }
    return (new);

}
