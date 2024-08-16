#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 *
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list;

    if (!list)
        return (NULL);

    while (current->express)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n >= value)
            break;
        current = current->express;
    }

    if (current)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        while (current->next)
        {
            printf("Value checked at index [%lu] = [%d]\n", current->next->index, current->next->n);
            if (current->next->n >= value)
                break;
            current = current->next;
        }

        if (current->n == value)
            return (current);
        if (current->next && current->next->n == value)
            return (current->next);
    }

    return (NULL);
}
