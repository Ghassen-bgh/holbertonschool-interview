#include"list.h"

/**
 * add_node_end - add node to the end of the list
 * @list: list to add node to
 * @str: string to add to node
 * Return: address of new node or NULL if failed
 */

List *add_node_end(List **list, char *str)
{
    List *new, *tmp;

    new = malloc(sizeof(List));
    if (new == NULL)
        return (NULL);
    new->str = strdup(str);
    if (new->str == NULL)
    {
        free(new);
        return (NULL);
    }
    if (*list == NULL)
    {
        new->next = new;
        new->prev = new;
        *list = new;
        return (new);
    }
    tmp = (*list)->prev;
    new->next = *list;
    new->prev = tmp;
    tmp->next = new;
    (*list)->prev = new;
    return (new);
}

/**
 * add_node_begin - add node to the beginning of the list
 * @list: list to add node to
 * @str: string to add to node
 * Return: address of new node or NULL if failed
 */
 List *add_node_begin(List **list, char *str)
 {
        List *new, *tmp;
    
        new = malloc(sizeof(List));
        if (new == NULL)
            return (NULL);
        new->str = strdup(str);
        if (new->str == NULL)
        {
            free(new);
            return (NULL);
        }
        if (*list == NULL)
        {
            new->next = new;
            new->prev = new;
            *list = new;
            return (new);
        }
        tmp = (*list)->prev;
        new->next = *list;
        new->prev = tmp;
        tmp->next = new;
        (*list)->prev = new;
        *list = new;
        return (new);
 }
 