#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * reverse_listint - reverses a listint_t linked list
 * @tmp: pointer to pointer of first node of listint_t list
 * Return: listint_t
 */
listint_t *reverseList(listint_t *tmp)
{
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (tmp != NULL)
    {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *tmp = *head;
    listint_t *tmp2 = *head;
    listint_t *rev = NULL;
    int i = 0, j = 0;

    if (head == NULL || *head == NULL)
        return (1);
    while (tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }
    if (i == 1)
        return (1);
    for (j = 0; j < i / 2; j++)
    {
        tmp2 = tmp2->next;
    }
    rev = reverseList(tmp2);
    tmp = *head;
    while (rev != NULL)
    {
        if (tmp->n != rev->n)
            return (0);
        tmp = tmp->next;
        rev = rev->next;
    }
    return (1);
}

