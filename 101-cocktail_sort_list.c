#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: A pointer to the head of the list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sort a doubly linked list in ascending order
 *                      using the Cocktail Shaker Sort algorithm.
 * @list: A pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left = NULL, *right = NULL, *current = NULL;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (right = *list; right->next != left; right = right->next)
        {
            if (right->n > right->next->n)
            {
                swap_nodes(list, right, right->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        left = right;
        for (current = right; current->prev != left; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}
